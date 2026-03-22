import grpc
from concurrent import futures
import time
import messenger_pb2
import messenger_pb2_grpc

class MessengerServicer(messenger_pb2_grpc.MessengerServicer):
    def SendMessage(self, request, context):
        print(f"收到来自 {request.sender} 的消息: {request.content}")
        reply_content = f"你好 {request.sender}, 我已经收到了你的消息: '{request.content}'"
        return messenger_pb2.MessageResponse(reply=reply_content, success=True)

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    messenger_pb2_grpc.add_MessengerServicer_to_server(MessengerServicer(), server)
    server.add_insecure_port('[::]:50051')
    print("gRPC Server 正在启动，监听端口 50051...")
    server.start()
    try:
        while True:
            time.sleep(86400)
    except KeyboardInterrupt:
        server.stop(0)

if __name__ == '__main__':
    serve()
