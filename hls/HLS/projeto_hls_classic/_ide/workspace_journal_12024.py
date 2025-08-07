# 2025-05-30T14:23:30.329704200
import vitis

client = vitis.create_client()
client.set_workspace(path="projeto_hls")

comp = client.create_hls_component(name = "teste",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="teste")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp = client.create_hls_component(name = "sensor_system",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

client.delete_component(name="teste")

comp = client.get_component(name="sensor_system")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

client.delete_component(name="sensor_system")

comp = client.create_hls_component(name = "hello",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="hello")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

client.delete_component(name="hello")

client.delete_component(name="hello")

comp = client.create_hls_component(name = "helloworld_functions",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="helloworld_functions")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

vitis.dispose()

