#pragma once
#ifndef LPR_H
#define LPR_H

#ifdef LPR_EXPORTS
#define LPR_API extern "C" __declspec(dllexport)
#else
#define LPR_API extern "C" __declspec(dllimport)
#endif // LPR_EXPORTES

#endif // !LPR_H
