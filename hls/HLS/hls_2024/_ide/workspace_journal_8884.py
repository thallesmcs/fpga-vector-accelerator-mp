# 2025-07-14T19:52:59.076786400
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2024")

comp = client.get_component(name="adder_new")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

vitis.dispose()

