# 2025-06-04T17:32:04.718362600
import vitis

client = vitis.create_client()
client.set_workspace(path="projeto_hls")

client.delete_component(name="helloworld_functions")

comp = client.create_hls_component(name = "add_sub",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="add_sub")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

vitis.dispose()

