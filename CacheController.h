/*
 * CacheController.h
 *
 *  Created on: 28-Sep-2011
 *      Author: gsiddardha
 */

#ifndef CACHECONTROLLER_H_
#define CACHECONTROLLER_H_

#include "Cache.h"

class CacheController {
	public:
		CacheController();
		virtual ~CacheController();

	private:
		Cache cacheMem;
};

#endif /* CACHECONTROLLER_H_ */
