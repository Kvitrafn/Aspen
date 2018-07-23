#include <sstream>
#include <climits>
#include <cstdlib>
#include <queue>
#include <string>
#include "mud.h"
#include "conf.h"
#include "callout.h"
#include "calloutManager.h"
#include "utils.h"

CalloutManager* CalloutManager::_instance;

CalloutManager::CalloutManager():_curid(1)
{
#ifdef PROFILE_CALLOUTS
    _fired = 0;
    _delta = 0;
    _deltaMin = LLONG_MAX;
    _deltaMax = 0;
#endif
}

void CalloutManager::Initialize()
{
    _instance = new CalloutManager();
}
void CalloutManager::Release()
{
    if (_instance)
        {
            delete _instance;
            _instance = nullptr;
        }
}

CalloutManager* CalloutManager::GetInstance()
{
    if (!_instance)
        {
            Initialize();
        }

    return _instance;
}

void CalloutManager::Update()
{
    if (_callouts.empty())
        {
            return;
        }

    auto cur = _callouts.top();
    if (cur->CanFire())
        {
#ifdef PROFILE_CALLOUTS
            _fired++;
            int delta = cur->GetDelta();
            _delta += delta;
            _deltaMin = Min<unsigned long long int>(_deltaMin, delta);
            _deltaMax = Max<unsigned long long int>(_deltaMax, delta);
#endif
            cur->Fire();
            _callouts.pop();
            if (cur->IsOneShot())
                {
                    cur.reset();
                }
            else
                {
                    cur->Reset();
                    _callouts.push(cur);
                }
        }
}

unsigned int CalloutManager::RegisterCallout(int sec, int msec, const CALLOUT_CB cb, bool oneShot)
{
    if (sec <= 0 && msec <= 0)
        {
            return 0;
        }

    auto call = std::make_shared<Callout>(sec, msec, cb, oneShot);
    call->SetId(_curid);
    _curid++;
    _callouts.push(call);
    return _curid-1;
}

std::string CalloutManager::Profile() const
{
#ifdef PROFILE_CALLOUTS
    std::stringstream st;
    double mind;
    double maxd;
    double avg;

    st << Repeat("-", 80) << std::endl;
    st << "Callout profile." << std::endl;
    if (_fired == 0)
        {
            st << "No callout data has been recorded yet, check back soon!" << std::endl;
            return st.str();
        }

    st << "Total callouts fired: " << _fired << "." << std::endl;
    avg = _delta/_fired;
    avg /= 1000.0F;
    mind = _deltaMin/1000.0F;
    maxd = _deltaMax/1000.0F;
    st <<"Average time: " << avg << ". Min time: " << mind << ". Max time: " << maxd << ".";
    return st.str();
#else
    return "No callout profiling information is currently available.";
#endif
}
