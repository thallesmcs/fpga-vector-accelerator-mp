# 2025-07-21T10:43:50.386448300
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

vitis.dispose()

