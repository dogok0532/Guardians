#pragma once

void SafeDelete(void** ptr)
{
	if(*ptr != nullptr)
		delete *ptr;

	*ptr = nullptr;
}

