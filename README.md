
### Fast parallel object cache for iOS

#Usage

1.file
```markdown
    /*创建*/
    _fileCache = [[DLFileCache alloc] init];
    _fileCache.cachePath = [NSString stringWithFormat:@"%@/ImageCache", [DLSandbox libCachePath]];
    _fileCache.cacheUser = @"user1";
    
    /*保存*/
    [_fileCache setObject:[NSData dataFromResource:@"testImage.png"] forKey:@"test1"];
    
    /*删除*/
    [_fileCache removeObjectForKey:@"test1"];
    
    /*获取*/
    NSData *imgaeData = [_fileCache objectForKey:@"test1"];

    /*缓存路径*/
    NSString *path = [_fileCache fileNameForKey:@"test1"];
```

-------

2.Memory
```markdown
    /*创建*/
    _memoryCache = [DLMemoryCache sharedInstance];
    
    /*保存*/
    [_memoryCache setObject:@"memory-value" forKey:@"memory-key"];
    
    /*删除*/
    [_memoryCache removeObjectForKey:@"memory-key"];

    /*获取*/
    [_memoryCache objectForKey:@"memory-key"];
```
-------

3.userDefaults
```markdown
    /*创建*/
    _userDefaults = [DLUserDefaults sharedInstance];
    
    /*保存*/
    [_userDefaults userDefaultsWrite:@"userDefaults-value" forKey:@"userDefaults-key"];
    
    /*删除*/
    [_userDefaults userDefaultsRemove:@"userDefaults-key"];
    
     /*获取*/
    [_userDefaults userDefaultsRead:@"userDefaults-key"];

```
-------

4.keychain
```markdown
    /*创建*/
    _keyChain =  [DLKeychain sharedInstance];
    _keyChain.defaultDomain = @"com.keychain.";
    
    /*保存*/
    [_keyChain keychainWrite:@"keychain-value" forKey:@"keychain-key"];
    
    /*删除*/
    [_keyChain keychainDelete:@"keychain-key"];
    
    /*获取*/
    [_keyChain keychainRead:@"keychain-key"];
```

For more details see [GitHub Flavored Markdown](https://github.com/LimingZou).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/LimingZou/dl-cache-ios-1/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.


