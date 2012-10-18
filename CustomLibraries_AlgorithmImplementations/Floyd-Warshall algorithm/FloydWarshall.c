#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <FloydWarshall.h>

static int* _apspl_ = NULL;
static ui _n_ = 0;

void initAM(ui n)
{
	_n_ = n;
	_apspl_ = malloc(sizeof(int) * _n_ * _n_);
	// _apspl_ is not initialized to INFINITY here because \
	   it would be a waste of computation if FWassigntoAM() \
	   is going to be used in future and not FWpopulateAM().
}

void _inittoINFINITY_()
{
	int i;
	for(i = 0; i < _n_ * _n_; i++)
		_apspl_[i] = INFINITY;
}

void FWpopulateAM(ui u, ui v, int w);
{
	static usi isinittoINFINITY = 0;
	if(!isinittoINFINITY)
	{
		_inittoINFINITY_();
		isinittoINFINITY = 1;
	}
	assert(w < INFINITY);
	if(w < _apspl_[u * _n_ + v])
		_apspl_[u * _n_ + v] = w;
}

void FWassigntoAM(int* source)
{
	assert(source);
	memcpy(_apspl_, source, sizeof(int) * _n_ * _n_);
}

void FWcomputeAPSPL()
{
	int i, j, k;
	for(k = 0; k < _n_; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(_apspl_[i * _n_ + k] + _apspl_[k * _n_ + j]
						> _apspl_[i * _n_ + j])
					_apspl_[i * _n_ + j] = _apspl_[i * _n_ + k]
										 + _apspl_[k * _n_ + j];
}

