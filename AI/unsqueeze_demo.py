import torch

def demo_unsqueeze():
    # 创建一个 2D Tensor
    # 形状为 (2, 3)
    x = torch.tensor([[1, 2, 3], 
                      [4, 5, 6]])
    
    print("--- 原始 Tensor ---")
    print(f"Value:\n{x}")
    print(f"Shape: {x.shape}")
    print()

    # 在 dim=0 处 unsqueeze
    # 形状将变为 (1, 2, 3)
    x0 = x.unsqueeze(0)
    print("--- unsqueeze(0) ---")
    print("在第 0 维（最外层）增加一个维度")
    print(f"Value:\n{x0}")
    print(f"Shape: {x0.shape}")
    print()

    # 在 dim=1 处 unsqueeze
    # 形状将变为 (2, 1, 3)
    x1 = x.unsqueeze(1)
    print("--- unsqueeze(1) ---")
    print("在第 1 维（中间）增加一个维度")
    print(f"Value:\n{x1}")
    print(f"Shape: {x1.shape}")
    print()

    # 在 dim=2 处 unsqueeze (或者 dim=-1)
    # 形状将变为 (2, 3, 1)
    x2 = x.unsqueeze(2)
    print("--- unsqueeze(2) ---")
    print("在第 2 维（最内层）增加一个维度")
    print(f"Value:\n{x2}")
    print(f"Shape: {x2.shape}")
    print()

if __name__ == "__main__":
    demo_unsqueeze()
