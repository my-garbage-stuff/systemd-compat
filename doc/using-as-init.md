# Using systemd-compat ad init
systemd-compat will call **/sbin/compat-init** script as init script.
You can create compat-init like this

```
#!/bin/sh
# openrc-init
exec /sbin/openrc-init
# busybox init
exec /bin/busybox init
```

Then you must create symlink

```
ln -s /etc/init.d/systemd /sbin/init
```
