#!/bin/bash

# 파일을 전송할 대상의 정보
destination_ip="172.20.10.6"
destination_user="kim"
destination_path="/home/kim"
destination_password="528491"


while true; do
    # 1초마다 파일을 전송
    scp -o StrictHostKeyChecking=no /sys/class/misc/FreescaleAccelerometer/data "$destination_user"@"$destination_ip":"$destination_path"


    sleep 1
done

