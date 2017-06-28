//
//  DLTriStateBOOL.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/24.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/DLMacros.h>
typedef NS_ENUM(NSInteger, DLTriStateBOOL)
{
    DLTriStateBOOLValueUnknown = -1,
    DLTriStateBOOLValueNO = 0,
    DLTriStateBOOLValueYES = 1,
};

DL_EXTERN DLTriStateBOOL DLTriStateBOOLFromBOOL(BOOL value);
DL_EXTERN DLTriStateBOOL DLTriStateBOOLFromNSNumber(NSNumber *value);
DL_EXTERN BOOL BOOLFromDLTriStateBOOL(DLTriStateBOOL value, BOOL defaultValue);
