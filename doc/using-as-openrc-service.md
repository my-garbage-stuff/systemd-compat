# Using as openrc service
You can link compat service with target service name.
If service file located at **lib/systemd/system/test.service** you should create symlink like this

```
# compat service located at /etc/init.d/systemd
ln -s systemd /etc/init.d/test
```
Then you can enable service
```
rc-update add test default
```