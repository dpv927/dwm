import psutil
import time

def net_data(interval=1):
    pre = psutil.net_io_counters()
    time.sleep(interval)
    post = psutil.net_io_counters()

    # Get sent and recieved data as bytes
    dsent = post.bytes_sent - pre.bytes_sent
    drecv = post.bytes_recv - pre.bytes_recv

    # Do only once
    dbits=1024*1024

    # Get sent data measure
    sunit = "B/s"
    if (dsent <= dbits):
        if(dsent > 1024):
            dsent/=1024
            sunit = "Kb/s"
    else:
        dsent/=(dbits)
        sunit = "Mb/s"

    # Get recieved data measure
    runit = "B/s"
    if (drecv <= dbits):
        if (drecv > 1024):
            drecv/=1024
            runit = "Kb/s"
    else:
        drecv/=(dbits)
        runit = "Mb/s"

    # Print results 
    print(f" {drecv:.2f} {runit}  {dsent:.2f} {sunit}")

if __name__ == "__main__":
    net_data()
