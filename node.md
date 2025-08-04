## node built in modules
- fs
- path
- os
- http
- events
- process
### fs
```js
readFile(filename, encoding, (err, data) => {
if(err) throw err;
// work with data
});
appendFile(filename, content_to_append, (err) => {
if(err) throw err;
})
```
