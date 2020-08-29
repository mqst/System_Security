#!/usr/bin/python3
import requests,json,sys,os
target=sys.argv[1]
apikey=sys.argv[2]
subdomains=set()
def shodan_subs():
    fetch_shodan=requests.get('https://api.shodan.io/dns/domain/'+target+'?key='+apikey)
    shodan_json=json.loads(fetch_shodan.text)

    for line in shodan_json["data"]:
        sub=line["subdomain"]
        subdomain=sub+'.'+target
        if subdomain not in subdomains:
            subdomains.add(subdomain)

def crtsh_subs():
    command="curl -s https://crt.sh/\?q\=\%."+target+"\&output\=json | jq -r '.[].name_value' | sed 's/\*\.//g' | sort -u"
    for subdomain in str(os.system(command)):
        if subdomain not in subdomains:
            subdomains.add(subdomain)
    for s in subdomains:
        print(s)

if __name__ == "__main__":
    if len (sys.argv) != 3:
        print("[~] subfetch by mqst\n\nUsage: python3 subfetch.py [Target] [Shodan_API_KEY]")
        sys.exit (1)
    else:
        shodan_subs()
        crtsh_subs()