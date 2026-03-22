import grpc
import messenger_pb2
import messenger_pb2_grpc

def run():
    # 连接到 server
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = messenger_pb2_grpc.MessengerStub(channel)
        
        # 构造请求
        sender_name = "KiloCode"
        message_content = "你好，这是一个 gRPC 测试消息！"
        
        print(f"正在发送消息: '{message_content}' 来自 {sender_name}")
        
        # 调用 RPC
        response = stub.SendMessage(messenger_pb2.MessageRequest(
            sender=sender_name,
            content=message_content
        ))
        
        # 处理响应
        if response.success:
            print(f"收到服务器回复: {response.reply}")
        else:
            print("消息发送失败。")

if __name__ == '__main__':
    run()
