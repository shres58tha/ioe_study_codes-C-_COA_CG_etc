unpack() {
    tail +9 "$0" > /tmp/xxx.$$
    chmod +x /tmp/xxx.$$
}
unpack
/tmp/xxx.$$ <add args here>
rm /tmp/xxx.$$
exit
<add the binary here>
