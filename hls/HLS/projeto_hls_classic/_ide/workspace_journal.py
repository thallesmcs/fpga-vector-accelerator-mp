# 2025-06-25T13:29:01.597391200
import vitis

client = vitis.create_client()
client.set_workspace(path="projeto_hls")

vitis.dispose()

