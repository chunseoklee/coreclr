#include <windows.h>
#include "corhdr.h"
#include "cor.h"
#include "cordebug.h"
#include "dbgshim.h"

using namespace std;

class ManagedCallback : public ICorDebugManagedCallback
{
// here all interface methods with nothing inside
  virtual HRESULT QueryInterface(REFIID riid, void** ppvObject) {
        if(riid == __uuidof(ICorDebugManagedCallback))
    {
        *ppvObject = static_cast<ICorDebugManagedCallback*>(this);
        AddRef();
        return S_OK;
    }
    else if(riid == __uuidof(IUnknown))
    {
        *ppvObject = static_cast<IUnknown*>(this);
        AddRef();
        return S_OK;
    }
    else
    {
        return E_NOINTERFACE;
    }
  };
  virtual ULONG AddRef(){ return 0; };
  virtual ULONG Release() { return 0;};

  // ICorDebugManagedCallback interface
  virtual HRESULT Breakpoint(ICorDebugAppDomain  *pAppDomain,
                             ICorDebugThread     *pThread,  
                             ICorDebugBreakpoint *pBreakpoint);
  virtual HRESULT Break(ICorDebugAppDomain *pAppDomain,  
                        ICorDebugThread    *thread  );
  virtual HRESULT BreakpointSetError( ICorDebugAppDomain  *pAppDomain,  
                                      ICorDebugThread     *pThread,  
                                      ICorDebugBreakpoint *pBreakpoint,  
                                      DWORD                dwError  );
  virtual HRESULT StepComplete( ICorDebugAppDomain  *pAppDomain,  
                                ICorDebugThread     *pThread,  
                                ICorDebugStepper    *pStepper,
                                CorDebugStepReason  reason);
  virtual HRESULT Exception ( ICorDebugAppDomain *pAppDomain,  
                              ICorDebugThread    *pThread,  
                              BOOL                unhandled );
  virtual HRESULT EvalComplete ( ICorDebugAppDomain *pAppDomain,  
                                 ICorDebugThread    *pThread,  
                                 ICorDebugEval      *pEval );
  virtual HRESULT EvalException ( ICorDebugAppDomain *pAppDomain,  
                                  ICorDebugThread    *pThread,  
                                  ICorDebugEval      *pEval );

  virtual HRESULT STDMETHODCALLTYPE CreateProcess( 
                                                  /* [in] */ ICorDebugProcess *pProcess) ;
        
  virtual HRESULT STDMETHODCALLTYPE ExitProcess( 
                                                /* [in] */ ICorDebugProcess *pProcess) ;
        
  virtual HRESULT STDMETHODCALLTYPE CreateThread( 
                                                 /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                 /* [in] */ ICorDebugThread *thread) ;
        
  virtual HRESULT STDMETHODCALLTYPE ExitThread( 
                                               /* [in] */ ICorDebugAppDomain *pAppDomain,
                                               /* [in] */ ICorDebugThread *thread) ;
        
  virtual HRESULT STDMETHODCALLTYPE LoadModule( 
                                               /* [in] */ ICorDebugAppDomain *pAppDomain,
                                               /* [in] */ ICorDebugModule *pModule) ;
        
  virtual HRESULT STDMETHODCALLTYPE UnloadModule( 
                                                 /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                 /* [in] */ ICorDebugModule *pModule) ;
        
  virtual HRESULT STDMETHODCALLTYPE LoadClass( 
                                              /* [in] */ ICorDebugAppDomain *pAppDomain,
                                              /* [in] */ ICorDebugClass *c) ;
        
  virtual HRESULT STDMETHODCALLTYPE UnloadClass( 
                                                /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                /* [in] */ ICorDebugClass *c) ;
        
  virtual HRESULT STDMETHODCALLTYPE DebuggerError( 
                                                  /* [in] */ ICorDebugProcess *pProcess,
                                                  /* [in] */ HRESULT errorHR,
                                                  /* [in] */ DWORD errorCode) ;
        
  virtual HRESULT STDMETHODCALLTYPE LogMessage( 
                                               /* [in] */ ICorDebugAppDomain *pAppDomain,
                                               /* [in] */ ICorDebugThread *pThread,
                                               /* [in] */ LONG lLevel,
                                               /* [in] */ WCHAR *pLogSwitchName,
                                               /* [in] */ WCHAR *pMessage) ;
        
  virtual HRESULT STDMETHODCALLTYPE LogSwitch( 
                                              /* [in] */ ICorDebugAppDomain *pAppDomain,
                                              /* [in] */ ICorDebugThread *pThread,
                                              /* [in] */ LONG lLevel,
                                              /* [in] */ ULONG ulReason,
                                              /* [in] */ WCHAR *pLogSwitchName,
                                              /* [in] */ WCHAR *pParentName) ;
        
  virtual HRESULT STDMETHODCALLTYPE CreateAppDomain( 
                                                    /* [in] */ ICorDebugProcess *pProcess,
                                                    /* [in] */ ICorDebugAppDomain *pAppDomain) ;
        
  virtual HRESULT STDMETHODCALLTYPE ExitAppDomain( 
                                                  /* [in] */ ICorDebugProcess *pProcess,
                                                  /* [in] */ ICorDebugAppDomain *pAppDomain) ;
        
  virtual HRESULT STDMETHODCALLTYPE LoadAssembly( 
                                                 /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                 /* [in] */ ICorDebugAssembly *pAssembly);        
  virtual HRESULT STDMETHODCALLTYPE UnloadAssembly( 
                                                   /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                   /* [in] */ ICorDebugAssembly *pAssembly);
        
  virtual HRESULT STDMETHODCALLTYPE ControlCTrap( 
                                                 /* [in] */ ICorDebugProcess *pProcess);
        
  virtual HRESULT STDMETHODCALLTYPE NameChange( 
                                               /* [in] */ ICorDebugAppDomain *pAppDomain,
                                               /* [in] */ ICorDebugThread *pThread);
        
  virtual HRESULT STDMETHODCALLTYPE UpdateModuleSymbols( 
                                                        /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                        /* [in] */ ICorDebugModule *pModule,
                                                        /* [in] */ IStream *pSymbolStream);
        
  virtual HRESULT STDMETHODCALLTYPE EditAndContinueRemap( 
                                                         /* [in] */ ICorDebugAppDomain *pAppDomain,
                                                         /* [in] */ ICorDebugThread *pThread,
                                                         /* [in] */ ICorDebugFunction *pFunction,
                                                         /* [in] */ BOOL fAccurate);        
    
    
};

HRESULT STDMETHODCALLTYPE ManagedCallback::CreateProcess( 
                                        /* [in] */ ICorDebugProcess *pProcess)
{
  pProcess->Continue(FALSE);
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::ExitProcess( 
                                      /* [in] */ ICorDebugProcess *pProcess)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::CreateThread( 
                                       /* [in] */ ICorDebugAppDomain *pAppDomain,
                                       /* [in] */ ICorDebugThread *thread)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::ExitThread( 
                                     /* [in] */ ICorDebugAppDomain *pAppDomain,
                                     /* [in] */ ICorDebugThread *thread)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::LoadModule( 
                                     /* [in] */ ICorDebugAppDomain *pAppDomain,
                                     /* [in] */ ICorDebugModule *pModule)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::UnloadModule( 
                                       /* [in] */ ICorDebugAppDomain *pAppDomain,
                                       /* [in] */ ICorDebugModule *pModule)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::LoadClass( 
                                    /* [in] */ ICorDebugAppDomain *pAppDomain,
                                    /* [in] */ ICorDebugClass *c)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::UnloadClass( 
                                      /* [in] */ ICorDebugAppDomain *pAppDomain,
                                      /* [in] */ ICorDebugClass *c)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::DebuggerError( 
                                        /* [in] */ ICorDebugProcess *pProcess,
                                        /* [in] */ HRESULT errorHR,
                                        /* [in] */ DWORD errorCode)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::LogMessage( 
                                     /* [in] */ ICorDebugAppDomain *pAppDomain,
                                     /* [in] */ ICorDebugThread *pThread,
                                     /* [in] */ LONG lLevel,
                                     /* [in] */ WCHAR *pLogSwitchName,
                                     /* [in] */ WCHAR *pMessage)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::LogSwitch( 
                                    /* [in] */ ICorDebugAppDomain *pAppDomain,
                                    /* [in] */ ICorDebugThread *pThread,
                                    /* [in] */ LONG lLevel,
                                    /* [in] */ ULONG ulReason,
                                    /* [in] */ WCHAR *pLogSwitchName,
                                    /* [in] */ WCHAR *pParentName)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::CreateAppDomain( 
                                          /* [in] */ ICorDebugProcess *pProcess,
                                          /* [in] */ ICorDebugAppDomain *pAppDomain)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::ExitAppDomain( 
                                        /* [in] */ ICorDebugProcess *pProcess,
                                        /* [in] */ ICorDebugAppDomain *pAppDomain)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::LoadAssembly( 
                                       /* [in] */ ICorDebugAppDomain *pAppDomain,
                                       /* [in] */ ICorDebugAssembly *pAssembly)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::UnloadAssembly( 
                                         /* [in] */ ICorDebugAppDomain *pAppDomain,
                                         /* [in] */ ICorDebugAssembly *pAssembly)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::ControlCTrap( 
                                       /* [in] */ ICorDebugProcess *pProcess)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::NameChange( 
                                     /* [in] */ ICorDebugAppDomain *pAppDomain,
                                     /* [in] */ ICorDebugThread *pThread)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::UpdateModuleSymbols( 
                                              /* [in] */ ICorDebugAppDomain *pAppDomain,
                                              /* [in] */ ICorDebugModule *pModule,
                                              /* [in] */ IStream *pSymbolStream)
{
  return S_OK;
}
        
HRESULT STDMETHODCALLTYPE ManagedCallback::EditAndContinueRemap( 
                                               /* [in] */ ICorDebugAppDomain *pAppDomain,
                                               /* [in] */ ICorDebugThread *pThread,
                                               /* [in] */ ICorDebugFunction *pFunction,
                                               /* [in] */ BOOL fAccurate)
{
  return S_OK;
}

HRESULT ManagedCallback::EvalException (  
                                        ICorDebugAppDomain *pAppDomain,  
                                        ICorDebugThread    *pThread,  
                                        ICorDebugEval      *pEval  
                                          )
{
  return S_OK;
}


HRESULT ManagedCallback::EvalComplete ( ICorDebugAppDomain *pAppDomain,  
                                        ICorDebugThread    *pThread,  
                                        ICorDebugEval      *pEval )
{
  return S_OK;
}


HRESULT ManagedCallback::Exception ( ICorDebugAppDomain *pAppDomain,  
                    ICorDebugThread    *pThread,  
                    BOOL                unhandled )
{
  return S_OK;
}

HRESULT ManagedCallback::StepComplete(ICorDebugAppDomain  *pAppDomain,  
                                      ICorDebugThread     *pThread,  
                                      ICorDebugStepper    *pStepper,  
                                      CorDebugStepReason   reason)
{
  return S_OK;
}


HRESULT ManagedCallback::BreakpointSetError( ICorDebugAppDomain  *pAppDomain,  
                            ICorDebugThread     *pThread,  
                            ICorDebugBreakpoint *pBreakpoint,  
                            DWORD                dwError  )
{
  return S_OK;
}

HRESULT ManagedCallback::Breakpoint(ICorDebugAppDomain  *pAppDomain,  
                                    ICorDebugThread     *pThread,  
                                    ICorDebugBreakpoint *pBreakpoint)
{
  return S_OK;
}

HRESULT ManagedCallback::Break(ICorDebugAppDomain  *pAppDomain,  
                               ICorDebugThread     *pThread)
                               
{
  return S_OK;
}

DWORD ProcessId;
PVOID unregisterToken;
HANDLE ResumeHandle;

void
CallbackFunction(IUnknown* punk, void* parameter, HRESULT hr)
{
      if (hr == S_OK) {
          ICorDebug* pCordb = (ICorDebug *)punk;
        //hr = punk->QueryInterface(IID_ICorDebug, (void **)&pCordb);

        hr = pCordb->Initialize();

        ManagedCallback *callback = new ManagedCallback();
        hr = pCordb->SetManagedHandler(callback);

        ICorDebugProcess *process;
        hr = pCordb->DebugActiveProcess(ProcessId, FALSE, &process);

      }
      UnregisterForRuntimeStartup(unregisterToken);
}


int main(int argc,char** argv)
{

  LPWSTR cmdstr = new wchar_t[1000];
  MultiByteToWideChar(CP_UTF8, 0, argv[1], strlen(argv[1]), cmdstr, strlen(argv[1]));
    
  HRESULT hr = CreateProcessForLaunch(
    cmdstr,
    TRUE,
    0,
    0,
    &ProcessId,
    &ResumeHandle);
  
  RegisterForRuntimeStartup(ProcessId, CallbackFunction, 0, &unregisterToken);

  ResumeProcess(ResumeHandle);
  

  CloseResumeHandle(ResumeHandle);
  
  return 0;
}
