#pragma once

void SafeDelete(void** ptr)
{
	delete *ptr;
	*ptr = nullptr;
}