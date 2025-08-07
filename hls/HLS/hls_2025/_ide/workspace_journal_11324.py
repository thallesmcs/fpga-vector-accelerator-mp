# 2025-07-16T11:03:34.300036700
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

comp = client.create_hls_component(name = "soma_arrays_in_memory",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="soma_arrays_in_memory")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

status = comp.remove_cfg_files(cfg_files=["hls_config.cfg"])

status = comp.add_cfg_files(cfg_files=["hls_config.cfg"])

comp.run(operation="IMPLEMENTATION")

comp = client.create_hls_component(name = "matrix_mult_hw",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

client.delete_component(name="matrix_mult_hw")

vitis.dispose()

vitis.dispose()

vitis.dispose()

