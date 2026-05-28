import sys
from src import WalletFinder

def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--scan":
        count = int(sys.argv[2]) if len(sys.argv) > 2 else 10
        finder = WalletFinder()
        print(f"Scanning {count} random wallets...")
        results = finder.scan_random(count)
        for addr, bal, key in results:
            print(f"Address: {addr[:10]}... Balance: {bal} satoshi")
    else:
        print("Usage: python main.py --scan [count]")

if __name__ == "__main__":
    main()