import hashlib
import requests
from .generator import WalletGenerator

class WalletFinder:
    def __init__(self, api_endpoint="https://blockchain.info/balance?active="):
        self.api = api_endpoint
        self.generator = WalletGenerator()

    def check_balance(self, address):
        try:
            resp = requests.get(f"{self.api}{address}", timeout=5)
            data = resp.json()
            return data.get(address, {}).get("final_balance", 0)
        except:
            return -1

    def scan_random(self, count=100):
        results = []
        for _ in range(count):
            addr = self.generator.generate()
            balance = self.check_balance(addr)
            results.append((addr, balance, self.generator.get_private_key_pem()))
        return results