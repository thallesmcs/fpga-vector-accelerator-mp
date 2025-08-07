# 2025-07-18T16:43:56.021408900
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

comp = client.get_component(name="soma_arrays_50")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_100")
comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_200")
comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_400")
comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_800")
comp.run(operation="SYNTHESIS")

comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_1000")
comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

comp = client.get_component(name="soma_arrays_1600")
comp.run(operation="SYNTHESIS")

comp = client.get_component(name="soma_arrays_800")
comp.run(operation="SYNTHESIS")

comp = client.get_component(name="soma_arrays_1600")
comp.run(operation="SYNTHESIS")

comp = client.get_component(name="soma_arrays_800")
comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_1000")
comp.run(operation="IMPLEMENTATION")

comp = client.get_component(name="soma_arrays_1600")
comp.run(operation="IMPLEMENTATION")

vitis.dispose()

