# ego_network_generator.py
import random
from faker import Faker
import networkx as nx
import matplotlib.pyplot as plt

def generate_fake_graph(num_entities=100, density=0.1, ego_name='Ego'):
    fake = Faker('en_IN')
    G = nx.Graph()

    # ego node
    ego_id = 0
    G.add_node(ego_id, name=ego_name, number=ego_id, role='ego')

    # alters
    for i in range(1, num_entities + 1):
        name = fake.name()
        G.add_node(i, name=name, number=i, role='alter')
        G.add_edge(ego_id, i)

    # connection density setup
    p = float(density)

    alters = [n for n, d in G.nodes(data=True) if d['role'] == 'alter']
    for i in range(len(alters)):
        for j in range(i + 1, len(alters)):
            if random.random() < p:
                G.add_edge(alters[i], alters[j])

    return G


def visualize_graph(G, figsize=(10, 8)):
    pos = nx.spring_layout(G, seed=42)
    labels = {n: f"{d['name']} ({d['number']})" for n, d in G.nodes(data=True)}

    sizes = [800 if d['role'] == 'ego' else 300 for _, d in G.nodes(data=True)]
    colors = ['red' if d['role'] == 'ego' else 'skyblue' for _, d in G.nodes(data=True)]

    plt.figure(figsize=figsize)
    nx.draw(G, pos, labels=labels, node_size=sizes, node_color=colors, edge_color='gray', font_size=7)
    plt.title(f"Ego Network for {G.nodes[0]['name']}")
    plt.axis('off')
    plt.show()


if __name__ == "__main__":
    G = generate_fake_graph(num_entities=100, density=0.05, ego_name='Nithin')
    visualize_graph(G)
