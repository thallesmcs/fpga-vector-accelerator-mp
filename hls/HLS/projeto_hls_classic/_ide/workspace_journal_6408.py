# 2025-05-28T11:48:51.119266700
import vitis

client = vitis.create_client()
client.set_workspace(path="projeto_hls")

comp = client.create_hls_component(name = "perfect_loop",template = "vitis_hls_examples/Pipelining/Loops/perfect_loop")

comp = client.create_hls_component(name = "adder",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="adder")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp.run(operation="CO_SIMULATION")

client.delete_component(name="perfect_loop")

