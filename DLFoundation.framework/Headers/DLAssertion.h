//
//  DLAssertion.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -

#undef	ASSERT
#define ASSERT( __expr )	DLAssert( (__expr) ? YES : NO, #__expr, __PRETTY_FUNCTION__, __FILE__, __LINE__ )

#if __cplusplus
extern "C" {
#endif
    
    void DLAssertToggle( void );
    void DLAssertEnable( void );
    void DLAssertDisable( void );
    void DLAssert( BOOL flag, const char * expr, const char * function, const char * file, int line );
    
#if __cplusplus
};
#endif

