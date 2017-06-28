//
//  NSObject+DLJSON.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (DLJSON)

+ (id)objectsFromArray:(id)arr;
+ (id)objectsFromAny:(id)any;

+ (id)objectFromDictionary:(id)dict;
+ (id)objectFromString:(id)str;
+ (id)objectFromData:(id)data;
+ (id)objectFromAny:(id)any;

- (id)objectToDictionary;
- (id)objectToString;
- (id)objectToData;
- (id)objectZerolize;

- (id)objectToDictionaryUntilRootClass:(Class)rootClass;
- (id)objectToStringUntilRootClass:(Class)rootClass;
- (id)objectToDataUntilRootClass:(Class)rootClass;
- (id)objectZerolizeUntilRootClass:(Class)rootClass;

- (id)serializeObject;
+ (id)unserializeObject:(id)obj;

@end
