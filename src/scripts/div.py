import sys

def get_usage(used, total):
    return float(used)/float(total)

if __name__ == '__main__':
    usage = get_usage(
        sys.argv[1][:-3].replace(",", "."), 
        sys.argv[2][:-3].replace(",", ".")
    )
    print(f"{round(usage, 2)}")
