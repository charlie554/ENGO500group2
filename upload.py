import sys
import json
import requests
dstream=sys.argv[1]
data=sys.argv[2]
dstream=str(dstream)
token = "78cc7eb2-9394-4675-b231-ff0a377a3674"
url='http://pg-api.sensorup.com/st-playground/proxy/v1.0/Datastreams('+dstream+')/Observations'
headers= {
	"Content-Type":"application/json",
	"St-P-Access-Token":token,
	}
payload = {"result":data}
print(payload)
r=requests.post(url, data=json.dumps(payload), headers=headers)
print(r)
print(r.text)
