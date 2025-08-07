# 2025-07-28T10:31:37.942688500
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

vitis.dispose()

comp = client.get_component(name="soma_arrays_1600")
comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

vitis.dispose()

