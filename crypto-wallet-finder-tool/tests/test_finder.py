import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

from src import WalletFinder, WalletGenerator

def test_generator_creates_address():
    gen = WalletGenerator()
    addr = gen.generate()
    assert len(addr) == 40, "Address should be 40 hex chars"
    assert isinstance(addr, str)

def test_generator_private_key():
    gen = WalletGenerator()
    gen.generate()
    pem = gen.get_private_key_pem()
    assert pem.startswith("-----BEGIN RSA PRIVATE KEY-----")

def test_finder_initializes():
    finder = WalletFinder()
    assert finder.api is not None

def test_finder_scan_returns_list():
    finder = WalletFinder()
    results = finder.scan_random(count=1)
    assert len(results) == 1
    assert len(results[0]) == 3  # address, balance, key

if __name__ == "__main__":
    test_generator_creates_address()
    test_generator_private_key()
    test_finder_initializes()
    test_finder_scan_returns_list()
    print("All tests passed.")