file_path="/home/ecube/a.txt"

remote_path="ecube@172.20.10.7:/home/ecube/"

while inotifywait -e modify "$file_path"; do
    
        scp "$file_path" "$remote_path"
done

