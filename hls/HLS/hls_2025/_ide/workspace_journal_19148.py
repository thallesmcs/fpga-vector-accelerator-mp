# 2025-07-18T16:38:18.097305100
import vitis

client = vitis.create_client()
client.set_workspace(path="hls_2025")

comp = client.clone_component(name="soma_arrays_1000",new_name="soma_arrays_200")

comp = client.clone_component(name="soma_arrays_200",new_name="soma_arrays_50")

comp = client.clone_component(name="soma_arrays_50",new_name="soma_arrays_100")

comp = client.clone_component(name="soma_arrays_50",new_name="soma_arrays_400")

comp = client.clone_component(name="soma_arrays_100",new_name="soma_arrays_800")

comp = client.clone_component(name="soma_arrays_800",new_name="soma_arrays_1600")

vitis.dispose()

