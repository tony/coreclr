
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//

#ifndef CORECLRLOADER_H
#define CORECLRLOADER_H
typedef int (*InitializeCoreCLRFunction)(
    const char* exePath,
    const char* appDomainFriendlyName,
    int propertyCount,
    const char** propertyKeys,
    const char** propertyValues,
    void** hostHandle,
    unsigned int* domainId);

typedef int (*ShutdownCoreCLRFunction)(
            void* hostHandle,
            unsigned int domainId);

class CoreCLRLoader
{
private:
    InitializeCoreCLRFunction initializeCoreCLR;
    ShutdownCoreCLRFunction shutdownCoreCLR;
    void *coreclrLib;
    void* hostHandle;
    unsigned int domainId;
public:
    static CoreCLRLoader* Create(const char *coreClrPath);
    void* LoadFunction(const char* functionName);
    int Finish();
};
#endif // CORECLRLOADER_H

