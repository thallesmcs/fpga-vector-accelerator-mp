# 2025-07-14T19:49:20.354284200
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2024")

comp = client.create_hls_component(name = "hls_component",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="hls_component")
status = comp.remove_cfg_files(cfg_files=["hls_config.cfg"])

status = comp.add_cfg_files(cfg_files=["hls_config.cfg"])

client.delete_component(name="hls_component")

comp = client.create_hls_component(name = "adder_new",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="adder_new")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

vitis.dispose()

