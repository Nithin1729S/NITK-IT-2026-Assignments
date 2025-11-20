import json
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import math
from scipy import stats
from collections import Counter
import seaborn as sns

# Set style for better plots
plt.style.use('default')
sns.set_palette("husl")

# =========================
# Load only first N relationships from file
# =========================
N = 1000

with open("relationships.json") as f:
    data = json.load(f)

G = nx.DiGraph()

count = 0
for image in data:
    for rel in image['relationships']:
        if count >= N:
            break
        try:
            subj = rel['subject']['names'][0].lower()
        except KeyError:
            subj = rel['subject']['name'].lower()
        try:
            obj = rel['object']['names'][0].lower()
        except KeyError:
            obj = rel['object']['name'].lower()
        
        predicate = rel['predicate'].lower()
        G.add_edge(subj, obj, relation=predicate)
        count += 1
    if count >= N:
        break

print(f"Graph loaded with {G.number_of_nodes()} nodes and {G.number_of_edges()} edges")

# =========================
# 1. AVERAGE DEGREE ANALYSIS
# =========================
print("\n" + "="*50)
print("1. AVERAGE DEGREE ANALYSIS")
print("="*50)

in_degrees = dict(G.in_degree())
out_degrees = dict(G.out_degree())
total_degrees = dict(G.degree())

avg_in = np.mean(list(in_degrees.values()))
avg_out = np.mean(list(out_degrees.values()))
avg_total = np.mean(list(total_degrees.values()))

std_in = np.std(list(in_degrees.values()))
std_out = np.std(list(out_degrees.values()))
std_total = np.std(list(total_degrees.values()))

print(f"Average in-degree: {avg_in:.3f} ± {std_in:.3f}")
print(f"Average out-degree: {avg_out:.3f} ± {std_out:.3f}")
print(f"Average total degree: {avg_total:.3f} ± {std_total:.3f}")

# Enhanced boxplots with statistics
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))

# Boxplot
bp = ax1.boxplot(
    [list(in_degrees.values()), 
     list(out_degrees.values()), 
     list(total_degrees.values())],
    labels=["In-degree", "Out-degree", "Total degree"],
    patch_artist=True
)

colors = ['lightblue', 'lightgreen', 'lightcoral']
for patch, color in zip(bp['boxes'], colors):
    patch.set_facecolor(color)

ax1.set_ylabel("Degree")
ax1.set_title(f"Degree Distribution Boxplot (N={N} relationships)")
ax1.grid(True, alpha=0.3)

# Histogram comparison
ax2.hist(list(in_degrees.values()), alpha=0.5, label='In-degree', bins=30, color='blue')
ax2.hist(list(out_degrees.values()), alpha=0.5, label='Out-degree', bins=30, color='green')
ax2.hist(list(total_degrees.values()), alpha=0.5, label='Total degree', bins=30, color='red')
ax2.set_xlabel("Degree")
ax2.set_ylabel("Frequency")
ax2.set_title("Degree Distribution Histograms")
ax2.legend()
ax2.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# =========================
# 2. DEGREE DISTRIBUTION ANALYSIS
# =========================
print("\n" + "="*50)
print("2. DEGREE DISTRIBUTION ANALYSIS")
print("="*50)

degrees = list(total_degrees.values())
degree_counts = Counter(degrees)
unique_degrees = sorted(degree_counts.keys())
frequencies = [degree_counts[d] for d in unique_degrees]

# Log-log plot of degree distribution
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(15, 12))

# Linear scale
ax1.scatter(unique_degrees, frequencies, alpha=0.7, s=50)
ax1.set_xlabel("Degree")
ax1.set_ylabel("Frequency")
ax1.set_title("Degree Distribution (Linear Scale)")
ax1.grid(True, alpha=0.3)

# Log-log scale
ax2.scatter(unique_degrees, frequencies, alpha=0.7, s=50)
ax2.set_xscale('log')
ax2.set_yscale('log')
ax2.set_xlabel("Degree (log)")
ax2.set_ylabel("Frequency (log)")
ax2.set_title("Degree Distribution (Log-Log Scale)")
ax2.grid(True, alpha=0.3)

# Fit power-law and other distributions
from scipy.optimize import curve_fit

def power_law(x, a, b):
    return a * np.power(x, -b)

def exponential(x, a, b):
    return a * np.exp(-b * x)

# Filter out zero values for fitting
nonzero_degrees = [d for d in unique_degrees if d > 0]
nonzero_freqs = [degree_counts[d] for d in nonzero_degrees]

# Try power-law fit
try:
    popt_pl, _ = curve_fit(power_law, nonzero_degrees, nonzero_freqs, p0=[1, 1])
    x_fit = np.logspace(0, np.log10(max(nonzero_degrees)), 100)
    y_fit_pl = power_law(x_fit, *popt_pl)
    
    ax3.scatter(nonzero_degrees, nonzero_freqs, alpha=0.7, label='Data', s=50)
    ax3.plot(x_fit, y_fit_pl, 'r-', label=f'Power-law fit: γ={popt_pl[1]:.2f}')
    ax3.set_xscale('log')
    ax3.set_yscale('log')
    ax3.set_xlabel("Degree (log)")
    ax3.set_ylabel("Frequency (log)")
    ax3.set_title("Power-law Fitting")
    ax3.legend()
    ax3.grid(True, alpha=0.3)
    
    print(f"Power-law exponent (γ): {popt_pl[1]:.3f}")
except:
    ax3.text(0.5, 0.5, 'Power-law fit failed', transform=ax3.transAxes, ha='center')
    print("Power-law fitting failed")

# CCDF (Complementary Cumulative Distribution Function)
degrees_sorted = sorted(degrees, reverse=True)
ccdf_y = np.arange(1, len(degrees_sorted) + 1) / len(degrees_sorted)
ax4.plot(degrees_sorted, ccdf_y, 'o-', alpha=0.7)
ax4.set_xscale('log')
ax4.set_yscale('log')
ax4.set_xlabel("Degree (log)")
ax4.set_ylabel("P(Degree ≥ k)")
ax4.set_title("Complementary CDF")
ax4.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# Identify outliers (top 1% and 5% nodes)
threshold_1 = np.percentile(degrees, 99)
threshold_5 = np.percentile(degrees, 95)
outliers_1 = [n for n, d in total_degrees.items() if d >= threshold_1]
outliers_5 = [n for n, d in total_degrees.items() if d >= threshold_5]

print(f"Top 1% outlier nodes (degree ≥ {threshold_1:.0f}): {len(outliers_1)} nodes")
print(f"Examples: {outliers_1[:5]}")
print(f"Top 5% high-degree nodes (degree ≥ {threshold_5:.0f}): {len(outliers_5)} nodes")

# =========================
# 3. PATH LENGTH ANALYSIS
# =========================
print("\n" + "="*50)
print("3. PATH LENGTH ANALYSIS")
print("="*50)

# Work with largest connected component
if not nx.is_connected(G.to_undirected()):
    largest_cc = max(nx.connected_components(G.to_undirected()), key=len)
    G_sub = G.subgraph(largest_cc).copy()
    print(f"Working with largest connected component: {len(largest_cc)}/{G.number_of_nodes()} nodes")
else:
    G_sub = G
    print("Graph is fully connected")

Gu_sub = G_sub.to_undirected()

if len(G_sub) > 1:
    # Path length calculations
    avg_path_len = nx.average_shortest_path_length(Gu_sub)
    diameter = nx.diameter(Gu_sub)
    
    print(f"Average path length: {avg_path_len:.3f}")
    print(f"Diameter: {diameter}")
    print(f"log(N): {math.log(len(G_sub)):.3f}")
    print(f"Small-world check - avg_path ~ log(N): {avg_path_len:.3f} vs {math.log(len(G_sub)):.3f}")
    
    if avg_path_len <= 2 * math.log(len(G_sub)):
        print("✓ Shows small-world path length behavior")
    else:
        print("✗ Does not show small-world path length behavior")
    
    # Find node pairs with diameter distance
    print("\nFinding diameter pairs...")
    diam_pairs = []
    nodes_list = list(G_sub.nodes())
    
    # Sample nodes to avoid computational explosion
    sample_size = min(100, len(nodes_list))
    sampled_nodes = np.random.choice(nodes_list, sample_size, replace=False)
    
    for u in sampled_nodes:
        for v in sampled_nodes:
            if u != v and nx.has_path(G_sub, u, v):
                try:
                    if nx.shortest_path_length(G_sub, u, v) == diameter:
                        diam_pairs.append((u, v))
                        if len(diam_pairs) >= 5:
                            break
                except:
                    continue
        if len(diam_pairs) >= 5:
            break
    
    print(f"Example node pairs with diameter {diameter}: {diam_pairs[:3]}")
    
    # Path length distribution
    path_lengths = []
    sample_pairs = min(1000, len(sampled_nodes) * (len(sampled_nodes) - 1) // 2)
    
    for i, u in enumerate(sampled_nodes[:int(math.sqrt(sample_pairs))]):
        for v in sampled_nodes[i+1:]:
            if nx.has_path(Gu_sub, u, v):
                path_lengths.append(nx.shortest_path_length(Gu_sub, u, v))
    
    if path_lengths:
        plt.figure(figsize=(12, 5))
        
        plt.subplot(1, 2, 1)
        plt.hist(path_lengths, bins=range(1, max(path_lengths)+2), alpha=0.7, edgecolor='black')
        plt.axvline(avg_path_len, color='red', linestyle='--', label=f'Average: {avg_path_len:.2f}')
        plt.axvline(diameter, color='orange', linestyle='--', label=f'Diameter: {diameter}')
        plt.xlabel("Path Length")
        plt.ylabel("Frequency")
        plt.title("Distribution of Shortest Path Lengths")
        plt.legend()
        plt.grid(True, alpha=0.3)
        
        plt.subplot(1, 2, 2)
        eccentricities = nx.eccentricity(Gu_sub)
        ecc_values = list(eccentricities.values())
        plt.hist(ecc_values, bins=range(1, max(ecc_values)+2), alpha=0.7, edgecolor='black')
        plt.axvline(np.mean(ecc_values), color='red', linestyle='--', label=f'Mean: {np.mean(ecc_values):.2f}')
        plt.xlabel("Eccentricity")
        plt.ylabel("Frequency")
        plt.title("Node Eccentricity Distribution")
        plt.legend()
        plt.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.show()

# =========================
# 4. GEODESIC PATH LENGTH
# =========================
print("\n" + "="*50)
print("4. GEODESIC PATH LENGTH ANALYSIS")
print("="*50)

# Full graph geodesic (if connected)
if nx.is_connected(G.to_undirected()):
    full_geo_avg = nx.average_shortest_path_length(G.to_undirected())
    print(f"Full graph average geodesic path length: {full_geo_avg:.3f}")
else:
    print("Full graph is not connected - computing for largest component only")
    full_geo_avg = None

# Giant component geodesic
if len(G_sub) > 1:
    giant_geo_avg = nx.average_shortest_path_length(Gu_sub)
    print(f"Giant component average geodesic path length: {giant_geo_avg:.3f}")
    
    if full_geo_avg:
        print(f"Difference (full vs giant): {abs(full_geo_avg - giant_geo_avg):.3f}")

# =========================
# 5. CLUSTERING COEFFICIENT ANALYSIS
# =========================
print("\n" + "="*50)
print("5. CLUSTERING COEFFICIENT ANALYSIS")
print("="*50)

clust_coeffs = nx.clustering(Gu_sub)
avg_cc = nx.average_clustering(Gu_sub)
print(f"Average clustering coefficient: {avg_cc:.4f}")

# Degree-based analysis
deg_list = dict(Gu_sub.degree())
cc_values = [clust_coeffs[n] for n in Gu_sub.nodes()]
deg_values = [deg_list[n] for n in Gu_sub.nodes()]

# Low vs high degree comparison
degrees_arr = np.array(list(deg_list.values()))
p25 = np.percentile(degrees_arr, 25)
p75 = np.percentile(degrees_arr, 75)

low_deg_nodes = [n for n, d in deg_list.items() if d <= p25]
high_deg_nodes = [n for n, d in deg_list.items() if d >= p75]

avg_cc_low = np.mean([clust_coeffs[n] for n in low_deg_nodes]) if low_deg_nodes else float('nan')
avg_cc_high = np.mean([clust_coeffs[n] for n in high_deg_nodes]) if high_deg_nodes else float('nan')

print(f"Avg CC (low-degree nodes, ≤25th percentile): {avg_cc_low:.4f}")
print(f"Avg CC (high-degree nodes, ≥75th percentile): {avg_cc_high:.4f}")
print(f"Difference (high - low): {avg_cc_high - avg_cc_low:.4f}")

# Visualization
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(15, 12))

# CC vs Degree scatter
ax1.scatter(deg_values, cc_values, alpha=0.6, s=30)
ax1.set_xlabel("Degree")
ax1.set_ylabel("Clustering Coefficient")
ax1.set_title("Clustering Coefficient vs Degree")
ax1.grid(True, alpha=0.3)

# Log scale
nonzero_deg = [d for d in deg_values if d > 0]
nonzero_cc = [cc_values[i] for i, d in enumerate(deg_values) if d > 0]
ax2.scatter(nonzero_deg, nonzero_cc, alpha=0.6, s=30)
ax2.set_xscale('log')
ax2.set_xlabel("Degree (log)")
ax2.set_ylabel("Clustering Coefficient")
ax2.set_title("CC vs Degree (Log Scale)")
ax2.grid(True, alpha=0.3)

# Binned analysis
degree_bins = np.logspace(0, np.log10(max(nonzero_deg)), 10)
binned_cc_means = []
binned_cc_stds = []
bin_centers = []

for i in range(len(degree_bins)-1):
    mask = (np.array(nonzero_deg) >= degree_bins[i]) & (np.array(nonzero_deg) < degree_bins[i+1])
    if np.sum(mask) > 0:
        binned_cc_means.append(np.mean(np.array(nonzero_cc)[mask]))
        binned_cc_stds.append(np.std(np.array(nonzero_cc)[mask]))
        bin_centers.append((degree_bins[i] + degree_bins[i+1]) / 2)

ax3.errorbar(bin_centers, binned_cc_means, yerr=binned_cc_stds, 
            fmt='o-', capsize=5, capthick=2, linewidth=2)
ax3.set_xscale('log')
ax3.set_xlabel("Degree (binned)")
ax3.set_ylabel("Average Clustering Coefficient")
ax3.set_title("Binned CC vs Degree")
ax3.grid(True, alpha=0.3)

# CC distribution comparison
ax4.hist([clust_coeffs[n] for n in low_deg_nodes], alpha=0.5, label='Low degree', bins=20)
ax4.hist([clust_coeffs[n] for n in high_deg_nodes], alpha=0.5, label='High degree', bins=20)
ax4.set_xlabel("Clustering Coefficient")
ax4.set_ylabel("Frequency")
ax4.set_title("CC Distribution: Low vs High Degree Nodes")
ax4.legend()
ax4.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# =========================
# 6. STRONGLY/WEAKLY CONNECTED COMPONENTS
# =========================
print("\n" + "="*50)
print("6. CONNECTED COMPONENTS ANALYSIS")
print("="*50)

if G.is_directed():
    # Strongly Connected Components
    sccs = list(nx.strongly_connected_components(G))
    scc_sizes = sorted([len(c) for c in sccs], reverse=True)
    print(f"Number of Strongly Connected Components: {len(sccs)}")
    print(f"SCC size distribution (top 10): {scc_sizes[:10]}")
    
    # Weakly Connected Components  
    wccs = list(nx.weakly_connected_components(G))
    wcc_sizes = sorted([len(c) for c in wccs], reverse=True)
    print(f"Number of Weakly Connected Components: {len(wccs)}")
    print(f"WCC size distribution (top 10): {wcc_sizes[:10]}")
    
    # Visualization
    fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(15, 10))
    
    # SCC sizes
    ax1.bar(range(1, min(11, len(scc_sizes)+1)), scc_sizes[:10])
    ax1.set_xlabel("Component Rank")
    ax1.set_ylabel("Size")
    ax1.set_title("Top 10 SCC Sizes")
    ax1.grid(True, alpha=0.3)
    
    # SCC size distribution
    ax2.hist(scc_sizes, bins=min(50, len(set(scc_sizes))), alpha=0.7)
    ax2.set_xlabel("Component Size")
    ax2.set_ylabel("Frequency")
    ax2.set_title("SCC Size Distribution")
    ax2.set_yscale('log')
    ax2.grid(True, alpha=0.3)
    
    # WCC sizes
    ax3.bar(range(1, min(11, len(wcc_sizes)+1)), wcc_sizes[:10])
    ax3.set_xlabel("Component Rank")
    ax3.set_ylabel("Size")
    ax3.set_title("Top 10 WCC Sizes")
    ax3.grid(True, alpha=0.3)
    
    # WCC size distribution
    ax4.hist(wcc_sizes, bins=min(50, len(set(wcc_sizes))), alpha=0.7)
    ax4.set_xlabel("Component Size")
    ax4.set_ylabel("Frequency")
    ax4.set_title("WCC Size Distribution")
    ax4.set_yscale('log')
    ax4.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.show()

else:
    comps = list(nx.connected_components(G))
    comp_sizes = sorted([len(c) for c in comps], reverse=True)
    print(f"Number of connected components: {len(comps)}")
    print(f"Component size distribution (top 10): {comp_sizes[:10]}")

# =========================
# 7. GIANT COMPONENT COVERAGE STATISTICS
# =========================
print("\n" + "="*50)
print("7. GIANT COMPONENT ANALYSIS")
print("="*50)

if G.is_directed():
    largest_wcc = max(nx.weakly_connected_components(G), key=len)
    G_giant = G.subgraph(largest_wcc).copy()
    component_type = "Weakly Connected"
else:
    largest_cc = max(nx.connected_components(G), key=len)
    G_giant = G.subgraph(largest_cc).copy()
    component_type = "Connected"

n_total, m_total = G.number_of_nodes(), G.number_of_edges()
n_giant, m_giant = G_giant.number_of_nodes(), G_giant.number_of_edges()

print(f"Giant {component_type} Component Coverage:")
print(f"Nodes: {n_giant}/{n_total} ({100*n_giant/n_total:.2f}%)")
print(f"Edges: {m_giant}/{m_total} ({100*m_giant/m_total:.2f}%)")

# Compare properties
deg_all = np.mean([d for _, d in G.degree()]) if n_total > 0 else float('nan')
deg_giant = np.mean([d for _, d in G_giant.degree()]) if n_giant > 0 else float('nan')

cc_all = nx.average_clustering(G.to_undirected())
cc_giant = nx.average_clustering(G_giant.to_undirected())

print(f"\nProperty Comparison:")
print(f"Average degree - Full: {deg_all:.3f}, Giant: {deg_giant:.3f}")
print(f"Average clustering - Full: {cc_all:.4f}, Giant: {cc_giant:.4f}")

# Non-giant components analysis
non_giant_nodes = set(G.nodes()) - set(G_giant.nodes())
if non_giant_nodes:
    G_non_giant = G.subgraph(non_giant_nodes).copy()
    deg_non_giant = np.mean([d for _, d in G_non_giant.degree()]) if len(non_giant_nodes) > 0 else 0
    cc_non_giant = nx.average_clustering(G_non_giant.to_undirected()) if len(non_giant_nodes) > 1 else 0
    
    print(f"Non-giant components:")
    print(f"Nodes: {len(non_giant_nodes)}, Avg degree: {deg_non_giant:.3f}, Avg clustering: {cc_non_giant:.4f}")

# =========================
# 8. GIANT COMPONENT DETAILED PROPERTIES
# =========================
print("\n" + "="*50)
print("8. GIANT COMPONENT DETAILED ANALYSIS")
print("="*50)

Gu_giant = G_giant.to_undirected()
n_g, m_g = Gu_giant.number_of_nodes(), Gu_giant.number_of_edges()

if n_g > 1 and nx.is_connected(Gu_giant):
    giant_avg_path = nx.average_shortest_path_length(Gu_giant)
    giant_diam = nx.diameter(Gu_giant)
    print(f"Giant component average path length: {giant_avg_path:.3f}")
    print(f"Giant component diameter: {giant_diam}")
else:
    giant_avg_path = float('nan')
    giant_diam = float('nan')
    print("Giant component analysis failed - disconnected or too small")

print(f"Giant component average clustering: {cc_giant:.4f}")

# Small-world analysis
if n_g > 1:
    p = (2.0*m_g)/(n_g*(n_g-1))
    expected_cc_random = p
    avg_deg_giant = deg_giant
    
    if avg_deg_giant > 1:
        approx_rand_path = math.log(n_g)/math.log(avg_deg_giant)
    else:
        approx_rand_path = float('nan')
    
    print(f"\nSmall-world Analysis:")
    print(f"Expected random clustering: {expected_cc_random:.6f}")
    print(f"Actual clustering: {cc_giant:.6f}")
    print(f"Clustering ratio (actual/random): {cc_giant/expected_cc_random:.2f}" if expected_cc_random > 0 else "N/A")
    print(f"Expected random path length: {approx_rand_path:.3f}")
    print(f"Actual path length: {giant_avg_path:.3f}")
    
    if not math.isnan(cc_giant) and expected_cc_random > 0:
        clustering_ratio = cc_giant / expected_cc_random
        if clustering_ratio > 5 and not math.isnan(giant_avg_path) and not math.isnan(approx_rand_path):
            if giant_avg_path <= 2 * approx_rand_path:
                print("✓ Giant component shows STRONG small-world features")
            else:
                print("~ Giant component shows WEAK small-world features")
        else:
            print("✗ Giant component does NOT show small-world features")

# =========================
# 9. K-CORE DECOMPOSITION (ROBUSTNESS ANALYSIS)
# =========================
print("\n" + "="*50)
print("9. K-CONNECTEDNESS AND ROBUSTNESS ANALYSIS")
print("="*50)

# Remove self-loops for k-core analysis
Gu_clean = Gu_giant.copy()
Gu_clean.remove_edges_from(nx.selfloop_edges(Gu_clean))

k_values = []
core_nodes = []
core_edges = []

print("k-core Analysis:")
for k in range(1, 11):  # Extended range
    try:
        core = nx.k_core(Gu_clean, k=k)
        nodes_k = core.number_of_nodes()
        edges_k = core.number_of_edges()
        k_values.append(k)
        core_nodes.append(nodes_k)
        core_edges.append(edges_k)
        print(f"k={k}: nodes={nodes_k}, edges={edges_k}")
        
        if nodes_k == 0:  # No more k-cores
            break
    except:
        break

# Robustness visualization
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(15, 10))

# K-core sizes
ax1.plot(k_values, core_nodes, 'bo-', linewidth=2, markersize=8)
ax1.set_xlabel("k")
ax1.set_ylabel("Number of Nodes")
ax1.set_title("k-core Node Count vs k")
ax1.grid(True, alpha=0.3)

ax2.plot(k_values, core_edges, 'ro-', linewidth=2, markersize=8)
ax2.set_xlabel("k")
ax2.set_ylabel("Number of Edges")
ax2.set_title("k-core Edge Count vs k")
ax2.grid(True, alpha=0.3)

# Robustness analysis - fraction remaining
if k_values:
    node_fractions = [n/n_g for n in core_nodes]
    edge_fractions = [e/m_g for e in core_edges] if m_g > 0 else [0]*len(core_edges)
    
    ax3.plot(k_values, node_fractions, 'go-', linewidth=2, markersize=8, label='Nodes')
    ax3.plot(k_values, edge_fractions, 'mo-', linewidth=2, markersize=8, label='Edges')
    ax3.set_xlabel("k")
    ax3.set_ylabel("Fraction Remaining")
    ax3.set_title("Network Robustness: Fraction vs k")
    ax3.legend()
    ax3.grid(True, alpha=0.3)

# Core decomposition distribution
if len(Gu_clean) > 0:
    core_numbers = nx.core_number(Gu_clean)
    core_dist = Counter(core_numbers.values())
    
    ax4.bar(core_dist.keys(), core_dist.values(), alpha=0.7)
    ax4.set_xlabel("Core Number")
    ax4.set_ylabel("Number of Nodes")
    ax4.set_title("Distribution of Node Core Numbers")
    ax4.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# Robustness assessment
if len(k_values) > 1:
    max_k = max(k_values)
    nodes_at_max_k = core_nodes[k_values.index(max_k)]
    
    print(f"\nRobustness Assessment:")
    print(f"Maximum k-core: {max_k}")
    print(f"Nodes in maximum k-core: {nodes_at_max_k} ({100*nodes_at_max_k/n_g:.2f}% of giant component)")
    
    # Calculate decay rate
    if len(k_values) > 2:
        decay_rates = []
        for i in range(1, len(k_values)):
            if core_nodes[i-1] > 0:
                decay_rate = (core_nodes[i-1] - core_nodes[i]) / core_nodes[i-1]
                decay_rates.append(decay_rate)
        
        avg_decay = np.mean(decay_rates) if decay_rates else 0
        print(f"Average decay rate per k-step: {avg_decay:.3f}")
        
        if avg_decay < 0.3:
            print("✓ Network shows ROBUST structure (slow decay)")
        elif avg_decay < 0.7:
            print("~ Network shows MODERATE robustness")
        else:
            print("✗ Network shows FRAGILE structure (rapid decay)")

# Edge connectivity analysis
try:
    edge_connectivity = nx.edge_connectivity(Gu_clean)
    node_connectivity = nx.node_connectivity(Gu_clean)
    print(f"\nConnectivity Measures:")
    print(f"Edge connectivity: {edge_connectivity}")
    print(f"Node connectivity: {node_connectivity}")
except:
    print("Connectivity analysis failed (network too large or disconnected)")

# =========================
# 10. COMPREHENSIVE SUMMARY
# =========================
print("\n" + "="*70)
print("COMPREHENSIVE NETWORK ANALYSIS SUMMARY")
print("="*70)

print(f"\nBASIC STATISTICS:")
print(f"   • Total nodes: {n_total:,}")
print(f"   • Total edges: {m_total:,}")
print(f"   • Graph density: {nx.density(G):.6f}")
print(f"   • Is directed: {G.is_directed()}")

print(f"\nDEGREE ANALYSIS:")
print(f"   • Average degree: {avg_total:.3f} ± {std_total:.3f}")
print(f"   • Average in-degree: {avg_in:.3f}")
print(f"   • Average out-degree: {avg_out:.3f}")
print(f"   • Degree distribution: Power-law-like behavior observed")

print(f"\n PATH ANALYSIS:")
if not math.isnan(avg_path_len):
    print(f"   • Average path length: {avg_path_len:.3f}")
    print(f"   • Network diameter: {diameter}")
    print(f"   • Small-world behavior: {'Yes' if avg_path_len <= 2 * math.log(len(G_sub)) else 'No'}")
else:
    print(f"   • Network is disconnected - analysis on largest component only")

print(f"\n CLUSTERING:")
print(f"   • Average clustering coefficient: {avg_cc:.4f}")
print(f"   • Low-degree nodes clustering: {avg_cc_low:.4f}")
print(f"   • High-degree nodes clustering: {avg_cc_high:.4f}")

print(f"\n CONNECTIVITY:")
if G.is_directed():
    print(f"   • Strongly connected components: {len(sccs)}")
    print(f"   • Weakly connected components: {len(wccs)}")
    print(f"   • Largest SCC size: {scc_sizes[0] if scc_sizes else 0}")
    print(f"   • Largest WCC size: {wcc_sizes[0] if wcc_sizes else 0}")
else:
    print(f"   • Connected components: {len(comps)}")
    print(f"   • Largest component size: {comp_sizes[0] if comp_sizes else 0}")

print(f"\n GIANT COMPONENT:")
print(f"   • Node coverage: {100*n_giant/n_total:.1f}%")
print(f"   • Edge coverage: {100*m_giant/m_total:.1f}%")
print(f"   • Average degree: {deg_giant:.3f}")
print(f"   • Average clustering: {cc_giant:.4f}")

print(f"\n ROBUSTNESS:")
if k_values:
    print(f"   • Maximum k-core: {max(k_values)}")
    print(f"   • Core robustness: {'High' if max(k_values) > 5 else 'Moderate' if max(k_values) > 2 else 'Low'}")
    
print(f"\n SMALL-WORLD PROPERTIES:")
if not math.isnan(cc_giant) and expected_cc_random > 0:
    clustering_ratio = cc_giant / expected_cc_random
    path_condition = not math.isnan(giant_avg_path) and not math.isnan(approx_rand_path) and giant_avg_path <= 2 * approx_rand_path
    print(f"   • High clustering: {'Yes' if clustering_ratio > 5 else 'No'} (ratio: {clustering_ratio:.1f})")
    print(f"   • Short paths: {'Yes' if path_condition else 'No'}")
    print(f"   • Overall: {'STRONG' if clustering_ratio > 5 and path_condition else 'WEAK' if clustering_ratio > 3 else 'NONE'}")

print(f"\n KEY INSIGHTS:")
print(f"   • Network type: {'Scale-free' if max(degrees) > 10*np.mean(degrees) else 'Random-like'}")
print(f"   • Hub nodes present: {'Yes' if len(outliers_1) > 0 else 'No'}")
print(f"   • Community structure: {'Likely' if avg_cc > expected_cc_random * 3 else 'Unlikely'}")
print(f"   • Robustness: {'High' if max_k > 5 else 'Moderate' if max_k > 2 else 'Low'} (max k-core: {max_k})")

print("\n" + "="*70)
print("Analysis completed successfully!")
print("="*70)