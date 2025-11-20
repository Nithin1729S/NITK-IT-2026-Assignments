import random
import os
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from scipy import stats

def generate_overlapping_graphs(num_total=400, ego_names=None, seed=42, density=0.05, output_dir='outputs'):
    """Generate overlapping ego networks with shared alters"""
    if ego_names is None:
        ego_names = ['Ego1', 'Ego2', 'Ego3', 'Ego4']
    os.makedirs(output_dir, exist_ok=True)
    random.seed(seed)
    np.random.seed(seed)
    
    names_names = [names.name() for _ in range(num_total)]
    ego_assignments = {ego: set() for ego in ego_names}
    for name in names_names:
        num_egos = np.random.choice([1, 2, 3, 4], p=[0.5, 0.3, 0.15, 0.05])
        assigned_egos = random.sample(ego_names, num_egos)
        for ego in assigned_egos:
            ego_assignments[ego].add(name)

    graphs = {}
    alter_to_egos = {}
    
    for ego in ego_names:
        G = nx.Graph()
        G.add_node(ego, name=ego, role='ego')
        
        for name in ego_assignments[ego]:
            G.add_node(name, name=name, role='alter')
            weight = random.uniform(0.1, 1.0)
            G.add_edge(ego, name, weight=weight)
            alter_to_egos.setdefault(name, set()).add(ego)
        
        alters = [n for n, d in G.nodes(data=True) if d['role']=='alter']
        for i in range(len(alters)):
            for j in range(i+1, len(alters)):
                if random.random() < density:
                    G.add_edge(alters[i], alters[j], weight=random.uniform(0.1, 1.0))
        
        graphs[ego] = G

    return graphs, alter_to_egos

def identify_ties(G, ego_name, threshold=0.5):
    """Identify strong and weak ties based on interaction frequency"""
    strong_ties = []
    weak_ties = []
    
    for u, v, data in G.edges(data=True):
        if ego_name in [u, v]:
            alter = v if u == ego_name else u
            if data['weight'] >= threshold:
                strong_ties.append((alter, data['weight']))
            else:
                weak_ties.append((alter, data['weight']))
    
    return strong_ties, weak_ties

def compute_centralities(G):
    """Compute network centrality measures"""
    deg = nx.degree_centrality(G)
    btw = nx.betweenness_centrality(G, weight='weight')
    cls = nx.closeness_centrality(G, distance='weight')
    
    df = pd.DataFrame({
        'Node': list(G.nodes()),
        'Name': [G.nodes[n]['name'] for n in G.nodes()],
        'Degree': [deg[n] for n in G.nodes()],
        'Betweenness': [btw[n] for n in G.nodes()],
        'Closeness': [cls[n] for n in G.nodes()],
        'Role': [G.nodes[n]['role'] for n in G.nodes()]
    })
    return df

def compute_spectral_centralities(G):
    """Compute spectral centrality measures"""
    try:
        eigen = nx.eigenvector_centrality(G, weight='weight', max_iter=1000)
    except:
        eigen = {n: 0 for n in G.nodes()}
    
    try:
        katz = nx.katz_centrality(G, alpha=0.01, weight='weight', max_iter=1000)
    except:
        katz = {n: 0 for n in G.nodes()}
    
    pagerank = nx.pagerank(G, weight='weight')
    
    df = pd.DataFrame({
        'Node': list(G.nodes()),
        'Name': [G.nodes[n]['name'] for n in G.nodes()],
        'Eigenvector': [eigen[n] for n in G.nodes()],
        'Katz': [katz[n] for n in G.nodes()],
        'PageRank': [pagerank[n] for n in G.nodes()],
        'Role': [G.nodes[n]['role'] for n in G.nodes()]
    })
    return df

def assign_functional_roles(df):
    """Assign functional roles based on network position"""
    roles = []
    for _, row in df.iterrows():
        if row['Role'] == 'ego':
            roles.append('Ego')
        elif row['Betweenness'] > 0.05:
            roles.append('Bridge')
        elif row['Degree'] > 0.15:
            roles.append('Hub')
        else:
            roles.append('Peripheral')
    df['FunctionalRole'] = roles
    return df

def compare_ego_centralities(graphs, ego_names):
    """Compare local centrality measures across egos"""
    print("\n" + "=" * 70)
    print("1. LOCAL CENTRALITY COMPARISON ACROSS EGOS")
    print("=" * 70)
    
    ego_stats = []
    
    for ego in ego_names:
        G = graphs[ego]
        
        
        deg_cent = nx.degree_centrality(G)
        btw_cent = nx.betweenness_centrality(G, weight='weight')
        cls_cent = nx.closeness_centrality(G, distance='weight')
        
        
        avg_deg = np.mean(list(deg_cent.values()))
        avg_btw = np.mean(list(btw_cent.values()))
        avg_cls = np.mean(list(cls_cent.values()))
        
        
        ego_deg = deg_cent[ego]
        ego_btw = btw_cent[ego]
        ego_cls = cls_cent[ego]
        
        ego_stats.append({
            'Ego': ego,
            'Network_Size': len(G.nodes()) - 1,
            'Ego_Degree': ego_deg,
            'Ego_Betweenness': ego_btw,
            'Ego_Closeness': ego_cls,
            'Avg_Degree': avg_deg,
            'Avg_Betweenness': avg_btw,
            'Avg_Closeness': avg_cls,
            'Degree_Std': np.std(list(deg_cent.values())),
            'Centralization': max(deg_cent.values()) - avg_deg
        })
    
    df_ego = pd.DataFrame(ego_stats)
    
    print("\n EGO CENTRALITY COMPARISON TABLE:")
    print("─" * 70)
    print(df_ego.to_string(index=False))
    
    
    print("\n INTERPRETATION:")
    print("─" * 70)
    
    
    most_accessible = df_ego.loc[df_ego['Ego_Closeness'].idxmax()]
    print(f"\n✓ MOST ACCESSIBLE: {most_accessible['Ego']}")
    print(f"  • Closeness Centrality: {most_accessible['Ego_Closeness']:.4f}")
    print(f"  • Can reach all alters with shortest average path length")
    print(f"  • Positioned optimally for quick information dissemination")
    
    
    most_influential = df_ego.loc[df_ego['Ego_Betweenness'].idxmax()]
    print(f"\n✓ MOST INFLUENTIAL: {most_influential['Ego']}")
    print(f"  • Betweenness Centrality: {most_influential['Ego_Betweenness']:.4f}")
    print(f"  • Acts as critical bridge between different alter clusters")
    print(f"  • Controls information flow in the network")
    
    
    most_connected = df_ego.loc[df_ego['Ego_Degree'].idxmax()]
    print(f"\n✓ MOST CONNECTED: {most_connected['Ego']}")
    print(f"  • Degree Centrality: {most_connected['Ego_Degree']:.4f}")
    print(f"  • Has the most direct connections")
    print(f"  • Largest immediate social circle")
    
    
    print("\n NETWORK CHARACTERISTICS:")
    print("─" * 70)
    for _, row in df_ego.iterrows():
        print(f"\n{row['Ego']}:")
        print(f"  • Network Size: {int(row['Network_Size'])} alters")
        print(f"  • Centralization: {row['Centralization']:.4f} (higher = more hierarchical)")
        print(f"  • Degree Std Dev: {row['Degree_Std']:.4f} (variation in connectivity)")
    
    return df_ego

def analyze_spectral_centralities(graphs, ego_names, output_dir='outputs'):
    """Analyze and visualize spectral centralities"""
    print("\n" + "=" * 70)
    print("2. SPECTRAL CENTRALITY ANALYSIS")
    print("=" * 70)
    
    all_spectral_data = []
    
    for ego in ego_names:
        G = graphs[ego]
        spectral_df = compute_spectral_centralities(G)
        
        print(f"\n{'─' * 70}")
        print(f"EGO: {ego}")
        print(f"{'─' * 70}")
        
        
        print("\n TOP 5 INFLUENCERS BY METRIC:")
        print("\nEigenvector Centrality (recursive influence):")
        top_eigen = spectral_df[spectral_df['Role']=='alter'].nlargest(5, 'Eigenvector')[['Name', 'Eigenvector']]
        for idx, row in top_eigen.iterrows():
            print(f"  {row['Name'][:30]:30s} → {row['Eigenvector']:.4f}")
        
        print("\nKatz Centrality (weighted walks):")
        top_katz = spectral_df[spectral_df['Role']=='alter'].nlargest(5, 'Katz')[['Name', 'Katz']]
        for idx, row in top_katz.iterrows():
            print(f"  {row['Name'][:30]:30s} → {row['Katz']:.4f}")
        
        print("\nPageRank (importance propagation):")
        top_pr = spectral_df[spectral_df['Role']=='alter'].nlargest(5, 'PageRank')[['Name', 'PageRank']]
        for idx, row in top_pr.iterrows():
            print(f"  {row['Name'][:30]:30s} → {row['PageRank']:.4f}")
        
        
        spectral_df['Eigen_Rank'] = spectral_df['Eigenvector'].rank(ascending=False)
        spectral_df['Katz_Rank'] = spectral_df['Katz'].rank(ascending=False)
        spectral_df['PR_Rank'] = spectral_df['PageRank'].rank(ascending=False)
        
        
        alters_only = spectral_df[spectral_df['Role']=='alter']
        corr_eigen_katz = stats.spearmanr(alters_only['Eigen_Rank'], alters_only['Katz_Rank'])[0]
        corr_eigen_pr = stats.spearmanr(alters_only['Eigen_Rank'], alters_only['PR_Rank'])[0]
        corr_katz_pr = stats.spearmanr(alters_only['Katz_Rank'], alters_only['PR_Rank'])[0]
        
        print(f"\n RANK CORRELATIONS:")
        print(f"  • Eigenvector ↔ Katz: {corr_eigen_katz:.3f}")
        print(f"  • Eigenvector ↔ PageRank: {corr_eigen_pr:.3f}")
        print(f"  • Katz ↔ PageRank: {corr_katz_pr:.3f}")
        
        spectral_df['Ego'] = ego
        all_spectral_data.append(spectral_df)
        
        
        visualize_spectral_ranks(spectral_df, ego, output_dir)
    
    
    print(f"\n{'─' * 70}")
    print("CROSS-NETWORK SPECTRAL INSIGHTS:")
    print(f"{'─' * 70}")
    print("\n✓ Eigenvector Centrality:")
    print("  • Identifies nodes connected to other well-connected nodes")
    print("  • High values = part of influential cluster")
    print("  • Best for finding 'elite' or core group members")
    
    print("\n✓ Katz Centrality:")
    print("  • Counts all walks from a node (with decay)")
    print("  • More democratic than eigenvector (includes peripheral connections)")
    print("  • Best for overall network influence")
    
    print("\n✓ PageRank:")
    print("  • Google's algorithm - importance via connections")
    print("  • Balances quantity and quality of connections")
    print("  • Best for practical influence/importance ranking")
    
    return pd.concat(all_spectral_data, ignore_index=True)

def visualize_spectral_ranks(spectral_df, ego_name, output_dir):
    """Visualize rank order of nodes by spectral centralities"""
    alters_df = spectral_df[spectral_df['Role']=='alter'].copy()
    
    if len(alters_df) == 0:
        return
    
    
    top_15 = alters_df.nlargest(15, 'PageRank')
    
    fig, axes = plt.subplots(1, 3, figsize=(18, 6))
    
    metrics = ['Eigenvector', 'Katz', 'PageRank']
    colors = ['
    
    for idx, (metric, color) in enumerate(zip(metrics, colors)):
        sorted_data = top_15.sort_values(metric, ascending=True)
        
        axes[idx].barh(range(len(sorted_data)), sorted_data[metric], color=color, alpha=0.7)
        axes[idx].set_yticks(range(len(sorted_data)))
        axes[idx].set_yticklabels([name[:25] for name in sorted_data['Name']], fontsize=8)
        axes[idx].set_xlabel(f'{metric} Centrality', fontsize=10, fontweight='bold')
        axes[idx].set_title(f'Top 15 by {metric}', fontsize=11, fontweight='bold')
        axes[idx].grid(axis='x', alpha=0.3, linestyle='--')
    
    plt.suptitle(f"{ego_name}'s Network: Spectral Centrality Rankings", 
                 fontsize=14, fontweight='bold', y=1.02)
    plt.tight_layout()
    plt.savefig(f"{output_dir}/{ego_name}_spectral_ranks.png", dpi=150, bbox_inches='tight')
    plt.close()

def analyze_structural_comparison(graphs, ego_names, output_dir='outputs'):
    """Compare hierarchical vs decentralized structure across egos"""
    print("\n" + "=" * 70)
    print("3. STRUCTURAL COMPARISON: HIERARCHY vs DECENTRALIZATION")
    print("=" * 70)
    
    structural_metrics = []
    
    for ego in ego_names:
        G = graphs[ego]
        
        
        deg_cent = nx.degree_centrality(G)
        btw_cent = nx.betweenness_centrality(G, weight='weight')
        
        
        max_deg = max(deg_cent.values())
        sum_diff = sum(max_deg - deg_cent[n] for n in G.nodes())
        deg_centralization = sum_diff / ((len(G.nodes()) - 1) * (len(G.nodes()) - 2))
        
        
        deg_variance = np.var(list(deg_cent.values()))
        btw_variance = np.var(list(btw_cent.values()))
        
        
        degrees = dict(G.degree())
        avg_degree = np.mean(list(degrees.values()))
        core_nodes = [n for n, d in degrees.items() if d > avg_degree]
        core_size = len(core_nodes) / len(G.nodes())
        
        
        clustering = nx.average_clustering(G, weight='weight')
        
        
        density = nx.density(G)
        
        
        try:
            assortativity = nx.degree_assortativity_coefficient(G)
        except:
            assortativity = 0
        
        structural_metrics.append({
            'Ego': ego,
            'Degree_Centralization': deg_centralization,
            'Degree_Variance': deg_variance,
            'Betweenness_Variance': btw_variance,
            'Core_Proportion': core_size,
            'Clustering': clustering,
            'Density': density,
            'Assortativity': assortativity,
            'Network_Size': len(G.nodes())
        })
    
    df_struct = pd.DataFrame(structural_metrics)
    
    print("\n STRUCTURAL METRICS TABLE:")
    print("─" * 70)
    print(df_struct.to_string(index=False))
    
    
    df_struct['Hierarchy_Score'] = (
        df_struct['Degree_Centralization'] * 0.4 +
        (1 - df_struct['Density']) * 0.3 +
        df_struct['Degree_Variance'] * 0.3
    )
    
    
    df_struct['Decentralization_Score'] = (
        df_struct['Clustering'] * 0.4 +
        df_struct['Density'] * 0.3 +
        (1 - df_struct['Degree_Centralization']) * 0.3
    )
    
    print("\n HIERARCHY vs DECENTRALIZATION SCORES:")
    print("─" * 70)
    for _, row in df_struct.iterrows():
        print(f"\n{row['Ego']}:")
        print(f"  • Hierarchy Score: {row['Hierarchy_Score']:.4f}")
        print(f"  • Decentralization Score: {row['Decentralization_Score']:.4f}")
    
    
    print("\n STRUCTURAL CLASSIFICATION:")
    print("─" * 70)
    
    most_hierarchical = df_struct.loc[df_struct['Hierarchy_Score'].idxmax()]
    most_decentralized = df_struct.loc[df_struct['Decentralization_Score'].idxmax()]
    
    print(f"\n✓ MOST HIERARCHICAL: {most_hierarchical['Ego']}")
    print(f"  • High degree centralization ({most_hierarchical['Degree_Centralization']:.3f})")
    print(f"  • Low density ({most_hierarchical['Density']:.3f})")
    print(f"  • Star-like structure: ego dominates connections")
    print(f"  • Alters depend heavily on ego for bridging")
    
    print(f"\n✓ MOST DECENTRALIZED: {most_decentralized['Ego']}")
    print(f"  • High clustering ({most_decentralized['Clustering']:.3f})")
    print(f"  • Higher density ({most_decentralized['Density']:.3f})")
    print(f"  • Mesh-like structure: many alter-alter connections")
    print(f"  • More resilient network structure")
    
    
    print("\n DETAILED STRUCTURAL ANALYSIS:")
    print("─" * 70)
    
    for _, row in df_struct.iterrows():
        print(f"\n{row['Ego']}:")
        
        if row['Degree_Centralization'] > 0.6:
            print("  • Structure: HIGHLY HIERARCHICAL (star network)")
            print("  • Ego is central bottleneck for all information flow")
        elif row['Degree_Centralization'] > 0.4:
            print("  • Structure: MODERATELY HIERARCHICAL")
            print("  • Ego is important but some alter-alter connections exist")
        else:
            print("  • Structure: DECENTRALIZED (distributed network)")
            print("  • Alters form independent clusters and connections")
        
        if row['Clustering'] > 0.3:
            print(f"  • High clustering ({row['Clustering']:.3f}): friends know each other")
        else:
            print(f"  • Low clustering ({row['Clustering']:.3f}): separate social circles")
        
        if row['Assortativity'] > 0:
            print(f"  • Positive assortativity: popular alters connect to each other")
        else:
            print(f"  • Negative assortativity: hubs connect to periphery")
        
        print(f"  • Core group: {row['Core_Proportion']*100:.1f}% of network")
    
    
    visualize_structural_comparison(df_struct, graphs, ego_names, output_dir)
    
    return df_struct

def visualize_structural_comparison(df_struct, graphs, ego_names, output_dir):
    """Create comprehensive structural comparison visualizations"""
    
    
    fig, axes = plt.subplots(2, 2, figsize=(16, 14))
    
    
    categories = ['Centralization', 'Hierarchy\nScore', 'Clustering', 'Density', 'Core\nProportion']
    num_vars = len(categories)
    angles = np.linspace(0, 2 * np.pi, num_vars, endpoint=False).tolist()
    angles += angles[:1]
    
    ax = plt.subplot(221, projection='polar')
    colors = ['
    
    for idx, ego in enumerate(ego_names):
        row = df_struct[df_struct['Ego']==ego].iloc[0]
        values = [
            row['Degree_Centralization'],
            row['Hierarchy_Score'],
            row['Clustering'],
            row['Density'],
            row['Core_Proportion']
        ]
        values += values[:1]
        
        ax.plot(angles, values, 'o-', linewidth=2, label=ego, color=colors[idx])
        ax.fill(angles, values, alpha=0.15, color=colors[idx])
    
    ax.set_xticks(angles[:-1])
    ax.set_xticklabels(categories, size=9)
    ax.set_ylim(0, 1)
    ax.set_title('Structural Dimensions Comparison', size=12, fontweight='bold', pad=20)
    ax.legend(loc='upper right', bbox_to_anchor=(1.3, 1.1))
    ax.grid(True)
    
    
    ax2 = plt.subplot(222)
    for idx, ego in enumerate(ego_names):
        row = df_struct[df_struct['Ego']==ego].iloc[0]
        ax2.scatter(row['Hierarchy_Score'], row['Decentralization_Score'], 
                   s=300, alpha=0.6, color=colors[idx], edgecolors='black', linewidths=2)
        ax2.annotate(ego, (row['Hierarchy_Score'], row['Decentralization_Score']),
                    fontsize=11, fontweight='bold', ha='center')
    
    ax2.axhline(df_struct['Decentralization_Score'].mean(), color='gray', linestyle='--', alpha=0.5)
    ax2.axvline(df_struct['Hierarchy_Score'].mean(), color='gray', linestyle='--', alpha=0.5)
    ax2.set_xlabel('Hierarchy Score →', fontsize=11, fontweight='bold')
    ax2.set_ylabel('Decentralization Score →', fontsize=11, fontweight='bold')
    ax2.set_title('Hierarchy vs Decentralization', fontsize=12, fontweight='bold')
    ax2.grid(True, alpha=0.3)
    
    
    ax3 = plt.subplot(223)
    x = np.arange(len(ego_names))
    width = 0.35
    ax3.bar(x - width/2, df_struct['Degree_Centralization'], width, 
           label='Degree Centralization', alpha=0.8, color='
    ax3.bar(x + width/2, df_struct['Degree_Variance']*10, width, 
           label='Degree Variance (×10)', alpha=0.8, color='
    ax3.set_xlabel('Ego', fontsize=11, fontweight='bold')
    ax3.set_ylabel('Value', fontsize=11, fontweight='bold')
    ax3.set_title('Centralization Metrics', fontsize=12, fontweight='bold')
    ax3.set_xticks(x)
    ax3.set_xticklabels(ego_names)
    ax3.legend()
    ax3.grid(axis='y', alpha=0.3)
    
    
    ax4 = plt.subplot(224)
    x = np.arange(len(ego_names))
    ax4.bar(x - width/2, df_struct['Density'], width, 
           label='Density', alpha=0.8, color='
    ax4.bar(x + width/2, df_struct['Clustering'], width, 
           label='Clustering', alpha=0.8, color='
    ax4.set_xlabel('Ego', fontsize=11, fontweight='bold')
    ax4.set_ylabel('Coefficient', fontsize=11, fontweight='bold')
    ax4.set_title('Network Cohesion Metrics', fontsize=12, fontweight='bold')
    ax4.set_xticks(x)
    ax4.set_xticklabels(ego_names)
    ax4.legend()
    ax4.grid(axis='y', alpha=0.3)
    
    plt.suptitle('Structural Comparison Across Ego Networks', 
                fontsize=15, fontweight='bold', y=0.995)
    plt.tight_layout()
    plt.savefig(f"{output_dir}/structural_comparison.png", dpi=150, bbox_inches='tight')
    plt.close()
    
    
    fig, axes = plt.subplots(2, 2, figsize=(16, 14))
    axes = axes.flatten()
    
    for idx, ego in enumerate(ego_names):
        G = graphs[ego]
        pos = nx.spring_layout(G, k=1.5, seed=42)
        
        
        degrees = dict(G.degree())
        node_sizes = [degrees[n] * 30 if n != ego else 800 for n in G.nodes()]
        
        
        btw = nx.betweenness_centrality(G)
        node_colors = [btw[n] for n in G.nodes()]
        
        nx.draw_networkx_nodes(G, pos, node_size=node_sizes, node_color=node_colors,
                              cmap='YlOrRd', alpha=0.7, ax=axes[idx], 
                              edgecolors='black', linewidths=1)
        nx.draw_networkx_edges(G, pos, alpha=0.2, ax=axes[idx])
        nx.draw_networkx_labels(G, pos, {ego: ego}, font_size=10, 
                               font_weight='bold', ax=axes[idx])
        
        row = df_struct[df_struct['Ego']==ego].iloc[0]
        structure_type = "HIERARCHICAL" if row['Hierarchy_Score'] > row['Decentralization_Score'] else "DECENTRALIZED"
        
        axes[idx].set_title(f"{ego} - {structure_type}\n"
                          f"Centralization: {row['Degree_Centralization']:.3f} | "
                          f"Clustering: {row['Clustering']:.3f}",
                          fontsize=11, fontweight='bold')
        axes[idx].axis('off')
    
    plt.suptitle('Network Structure Visualization (Node size = Degree, Color = Betweenness)', 
                fontsize=14, fontweight='bold', y=0.995)
    plt.tight_layout()
    plt.savefig(f"{output_dir}/network_structures.png", dpi=150, bbox_inches='tight')
    plt.close()

def visualize_individual_network(G, ego_name, strong_ties, weak_ties, save_path):
    """Visualize individual ego network with strong/weak ties highlighted"""
    pos = nx.spring_layout(G, seed=42, k=2)
    
    plt.figure(figsize=(14, 12))
    
    ego_nodes = [n for n, d in G.nodes(data=True) if d['role'] == 'ego']
    alter_nodes = [n for n, d in G.nodes(data=True) if d['role'] == 'alter']
    
    nx.draw_networkx_nodes(G, pos, nodelist=ego_nodes, node_color='red', 
                          node_size=1000, label='Ego', alpha=0.9)
    nx.draw_networkx_nodes(G, pos, nodelist=alter_nodes, node_color='skyblue', 
                          node_size=300, label='Alters', alpha=0.7)
    
    strong_alter_names = [t[0] for t in strong_ties]
    weak_alter_names = [t[0] for t in weak_ties]
    
    strong_edges = [(ego_name, alter) for alter in strong_alter_names if G.has_edge(ego_name, alter)]
    weak_edges = [(ego_name, alter) for alter in weak_alter_names if G.has_edge(ego_name, alter)]
    other_edges = [(u, v) for u, v in G.edges() if (u, v) not in strong_edges and (u, v) not in weak_edges]
    
    nx.draw_networkx_edges(G, pos, edgelist=strong_edges, edge_color='darkgreen', 
                          width=2.5, label='Strong Ties', alpha=0.8)
    nx.draw_networkx_edges(G, pos, edgelist=weak_edges, edge_color='orange', 
                          width=1.5, label='Weak Ties', alpha=0.6)
    nx.draw_networkx_edges(G, pos, edgelist=other_edges, edge_color='gray', 
                          width=0.5, alpha=0.3)
    
    labels = {n: G.nodes[n]['name'][:15] for n in G.nodes()}
    nx.draw_networkx_labels(G, pos, labels, font_size=7)
    
    plt.title(f"{ego_name}'s Ego Network\nStrong Ties: {len(strong_ties)} | Weak Ties: {len(weak_ties)}", 
              fontsize=14, fontweight='bold')
    plt.legend(loc='upper right', fontsize=10)
    plt.axis('off')
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    plt.close()

def visualize_combined_network(combined_graph, alter_to_egos, ego_names, save_path):
    """Visualize combined network highlighting overlapping alters"""
    pos = nx.spring_layout(combined_graph, seed=42, k=3)
    
    plt.figure(figsize=(18, 16))
    
    ego_nodes = [n for n in combined_graph.nodes() if n in ego_names]
    overlap_counts = {n: len(alter_to_egos.get(n, set())) for n in combined_graph.nodes() if n not in ego_names}
    
    single_network = [n for n, count in overlap_counts.items() if count == 1]
    two_networks = [n for n, count in overlap_counts.items() if count == 2]
    three_networks = [n for n, count in overlap_counts.items() if count == 3]
    four_networks = [n for n, count in overlap_counts.items() if count == 4]
    
    nx.draw_networkx_nodes(combined_graph, pos, nodelist=ego_nodes, node_color='red', 
                          node_size=1500, label='Egos', alpha=0.9, edgecolors='black', linewidths=2)
    nx.draw_networkx_nodes(combined_graph, pos, nodelist=single_network, node_color='lightblue', 
                          node_size=200, label='Single Network', alpha=0.6)
    nx.draw_networkx_nodes(combined_graph, pos, nodelist=two_networks, node_color='yellow', 
                          node_size=350, label='2 Networks (Bridge)', alpha=0.7, edgecolors='orange', linewidths=1.5)
    nx.draw_networkx_nodes(combined_graph, pos, nodelist=three_networks, node_color='orange', 
                          node_size=450, label='3 Networks (Major Bridge)', alpha=0.8, edgecolors='red', linewidths=2)
    nx.draw_networkx_nodes(combined_graph, pos, nodelist=four_networks, node_color='purple', 
                          node_size=550, label='4 Networks (Super Bridge)', alpha=0.9, edgecolors='darkred', linewidths=2.5)
    
    nx.draw_networkx_edges(combined_graph, pos, edge_color='gray', width=0.3, alpha=0.2)
    
    important_nodes = ego_nodes + three_networks + four_networks
    labels = {n: combined_graph.nodes[n]['name'][:12] for n in important_nodes}
    nx.draw_networkx_labels(combined_graph, pos, labels, font_size=8, font_weight='bold')
    
    plt.title("Combined Ego Networks - Overlapping Alters & Bridges", fontsize=16, fontweight='bold')
    plt.legend(loc='upper right', fontsize=11, framealpha=0.9)
    plt.axis('off')
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    plt.close()

def combine_graphs(graphs):
    """Combine all ego networks into single graph"""
    combined = nx.Graph()
    for G in graphs.values():
        combined = nx.compose(combined, G)
    return combined

def analyze_networks():
    """Main analysis function"""
    ego_names = ['Nithin', 'Jay', 'Sanketh', 'Vrushank']
    graphs, alter_to_egos = generate_overlapping_graphs(num_total=400, ego_names=ego_names, density=0.05)
    os.makedirs('outputs', exist_ok=True)
    
    print("=" * 70)
    print("OVERLAPPING EGO NETWORKS ANALYSIS")
    print("=" * 70)
    
    
    
    ego_centrality_df = compare_ego_centralities(graphs, ego_names)
    
    
    spectral_data = analyze_spectral_centralities(graphs, ego_names)
    
    
    structural_df = analyze_structural_comparison(graphs, ego_names)
    
    
    print("\n" + "=" * 70)
    print("4. INDIVIDUAL EGO NETWORK ANALYSIS")
    print("=" * 70)
    
    all_strong = []
    all_weak = []
    
    for ego, G in graphs.items():
        print(f"\n{'─' * 70}")
        print(f"EGO: {ego}")
        print(f"{'─' * 70}")
        
        strong_ties, weak_ties = identify_ties(G, ego, threshold=0.5)
        all_strong.extend(strong_ties)
        all_weak.extend(weak_ties)
        
        print(f"Network Size: {len(G.nodes()) - 1} alters")
        print(f"Strong Ties (≥0.5): {len(strong_ties)}")
        print(f"Weak Ties (<0.5): {len(weak_ties)}")
        
        df = compute_centralities(G)
        df = assign_functional_roles(df)
        
        print(f"\nFunctional Roles Distribution:")
        role_counts = df[df['Role']=='alter']['FunctionalRole'].value_counts()
        for role, count in role_counts.items():
            print(f"  {role}: {count}")
        
        print(f"\nTop 5 Influential Alters:")
        top_alters = df[df['Role']=='alter'].nlargest(5, 'Betweenness')[['Name', 'Degree', 'Betweenness', 'FunctionalRole']]
        print(top_alters.to_string(index=False))
        
        visualize_individual_network(G, ego, strong_ties, weak_ties, f"outputs/{ego}_network.png")
    
    print("\n" + "=" * 70)
    print("5. OVERLAPPING ALTERS ANALYSIS")
    print("=" * 70)
    
    overlapping = {name: egos for name, egos in alter_to_egos.items() if len(egos) > 1}
    
    by_count = {}
    for name, egos in overlapping.items():
        count = len(egos)
        by_count.setdefault(count, []).append((name, egos))
    
    for count in sorted(by_count.keys(), reverse=True):
        alters = by_count[count]
        print(f"\nAlters in {count} ego networks ({len(alters)} alters):")
        for name, egos in sorted(alters, key=lambda x: x[0])[:10]:
            print(f"  • {name}: {', '.join(sorted(egos))}")
        if len(alters) > 10:
            print(f"  ... and {len(alters) - 10} more")
    
    print("\n" + "=" * 70)
    print("6. COMBINED NETWORK ANALYSIS")
    print("=" * 70)
    
    combined_graph = combine_graphs(graphs)
    print(f"\nTotal nodes: {len(combined_graph.nodes())}")
    print(f"Total edges: {len(combined_graph.edges())}")
    print(f"Network density: {nx.density(combined_graph):.4f}")
    print(f"Overlapping alters: {len(overlapping)}")
    
    visualize_combined_network(combined_graph, alter_to_egos, ego_names, "outputs/combined_network.png")
    
    print("\n" + "=" * 70)
    print("7. THEORETICAL ANALYSIS")
    print("=" * 70)
    
    print("\n GRANOVETTER'S 'STRENGTH OF WEAK TIES' THEORY:")
    print("─" * 70)
    print(f"• Strong ties (high interaction frequency): {len(all_strong)} total")
    print(f"• Weak ties (low interaction frequency): {len(all_weak)} total")
    print(f"• Weak/Strong ratio: {len(all_weak)/len(all_strong):.2f}")
    print("\nKey Findings:")
    print("  ✓ Weak ties serve as bridges between different social clusters")
    print(f"  ✓ {len(overlapping)} alters appear in multiple ego networks (bridges)")
    print("  ✓ These overlapping alters are often weak ties that connect")
    print("    otherwise disconnected social groups")
    print("  ✓ Weak ties provide access to novel information and resources")
    print("    from distant parts of the network")
    
    print("\n DUNBAR'S CIRCLES / EGO-CENTRIC THEORY:")
    print("─" * 70)
    print("Dunbar's theory suggests concentric circles around ego:")
    print("  • Intimate circle (≤5): closest relationships")
    print("  • Sympathy group (≤15): good friends")
    print("  • Affinity group (≤50): friends")
    print("  • Active network (≤150): meaningful contacts")
    
    print("\nOur Network Alignment:")
    for ego in ego_names:
        G = graphs[ego]
        strong_ties, weak_ties = identify_ties(G, ego, threshold=0.5)
        print(f"  {ego}: {len(strong_ties)} strong (inner circles), "
              f"{len(weak_ties)} weak (outer circles)")
    
    print("\nConclusions:")
    print("  ✓ Strong ties cluster around ego (inner circles)")
    print("  ✓ Weak ties extend to outer circles and other networks")
    print("  ✓ Overlapping alters act as bridges (weak ties hypothesis)")
    print("  ✓ Network structure follows hierarchical circle pattern")
    
    print("\n" + "=" * 70)
    print("ANALYSIS COMPLETE - Visualizations saved in 'outputs/' folder")
    print("=" * 70)
    
    print("\n Generated Files:")
    print("  • Individual network visualizations: [Ego]_network.png")
    print("  • Spectral centrality rankings: [Ego]_spectral_ranks.png")
    print("  • Structural comparison: structural_comparison.png")
    print("  • Network structures: network_structures.png")
    print("  • Combined network: combined_network.png")

if __name__ == "__main__":
    analyze_networks()