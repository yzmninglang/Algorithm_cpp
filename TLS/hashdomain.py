import hashlib

# 1. 模拟原始证书数据 (域名 + 公钥)
original_data = "Domain: yzm.com | Public_Key: RSA_KEY_789"
original_data = "Domain: yzk.com | Public_Key: RSA_KEY_789"
print(f"--- 原始证书数据 ---\n{original_data}\n")

# 2. 模拟 CA 生成哈希摘要 (指纹)
# 在现实中，这一步是自动的
original_hash = hashlib.sha256(original_data.encode()).hexdigest()
print(f"CA 生成的原始指纹:\n{original_hash}\n")

# --- 模拟攻击：黑客截获了数据并改了一个字符 ---
# 黑客把 yzm.com 改成了 yzn.com
tampered_data = "Domain: yzn.com | Public_Key: RSA_KEY_789"

# 3. 浏览器的“两路比对”环节
print("--- 浏览器验证开始 ---")

# 路线 A：浏览器根据收到的数据自己算一遍指纹
new_hash = hashlib.sha256(tampered_data.encode()).hexdigest()

# 路线 B：浏览器用 CA 公钥解开签名拿到原始指纹 (这里直接用我们存的 original_hash 模拟)
received_hash_from_signature = original_hash

print(f"路线 A (当前数据计算出的指纹):\n{new_hash}")
print(f"路线 B (签名里解密出的指纹):\n{received_hash_from_signature}")

# 4. 最终比对
if new_hash == received_hash_from_signature:
    print("\n✅ 验证通过：证书是真实的，未被篡改！")
else:
    print("\n❌ 验证失败：指纹对不上！证书已被黑客篡改！")