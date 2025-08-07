# 2025-05-30T16:37:38.753348800
import vitis

client = vitis.create_client()
client.set_workspace(path="projeto_hls")

comp = client.get_component(name="helloworld_functions")
comp.run(operation="C_SIMULATION")

client.delete_component(name="helloworld_functions")

comp = client.create_hls_component(name = "helloworld_functions",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp.run(operation="C_SIMULATION")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

vitis.dispose()

