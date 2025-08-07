# 2025-07-17T16:27:21.022886600
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

comp = client.create_hls_component(name = "soma_arrays_1000",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="soma_arrays_1000")
comp.run(operation="C_SIMULATION")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.create_hls_component(name = "soma_array_generic_10000",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="soma_array_generic_10000")
comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

vitis.dispose()

