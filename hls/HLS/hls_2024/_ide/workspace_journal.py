# 2025-08-04T18:11:37.023684400
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2024")

vitis.dispose()

