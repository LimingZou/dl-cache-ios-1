//
//  NSArray+DLExtension.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -

typedef NSMutableArray *	(^NSArrayAppendBlock)( id obj );
typedef NSMutableArray *	(^NSMutableArrayAppendBlock)( id obj );
typedef NSComparisonResult	(^NSMutableArrayCompareBlock)( id left, id right );

#pragma mark -

@interface NSArray(DLExtension)

@property (nonatomic, readonly) NSArrayAppendBlock			APPEND;
@property (nonatomic, readonly) NSMutableArray *			mutableArray;

- (NSArray *)head:(NSUInteger)count;
- (NSArray *)tail:(NSUInteger)count;

- (id)safeObjectAtIndex:(NSInteger)index;
- (NSArray *)safeSubarrayWithRange:(NSRange)range;

- (NSString *)join:(NSString *)delimiter;

@end

#pragma mark -

@interface NSMutableArray(DLExtension)

@property (nonatomic, readonly) NSMutableArrayAppendBlock	APPEND;

+ (NSMutableArray *)nonRetainingArray;

- (void)addUniqueObject:(id)object compare:(NSMutableArrayCompareBlock)compare;
- (void)addUniqueObjects:(const id [])objects count:(NSUInteger)count compare:(NSMutableArrayCompareBlock)compare;
- (void)addUniqueObjectsFromArray:(NSArray *)array compare:(NSMutableArrayCompareBlock)compare;

- (void)unique;
- (void)unique:(NSMutableArrayCompareBlock)compare;

- (void)sort;
- (void)sort:(NSMutableArrayCompareBlock)compare;

- (NSMutableArray *)pushHead:(NSObject *)obj;
- (NSMutableArray *)pushHeadN:(NSArray *)all;
- (NSMutableArray *)popTail;
- (NSMutableArray *)popTailN:(NSUInteger)n;

- (NSMutableArray *)pushTail:(NSObject *)obj;
- (NSMutableArray *)pushTailN:(NSArray *)all;
- (NSMutableArray *)popHead;
- (NSMutableArray *)popHeadN:(NSUInteger)n;

- (NSMutableArray *)keepHead:(NSUInteger)n;
- (NSMutableArray *)keepTail:(NSUInteger)n;

- (void)insertObjectNoRetain:(id)anObject atIndex:(NSUInteger)index;
- (void)addObjectNoRetain:(NSObject *)obj;
- (void)removeObjectNoRelease:(NSObject *)obj;
- (void)removeAllObjectsNoRelease;

- (void)removeObject:(NSObject *)obj usingComparator:(NSMutableArrayCompareBlock)cmptr;

- (NSMutableArray *)shuffle;

@end
