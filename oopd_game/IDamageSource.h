#pragma once

class IDamageSource {
	virtual ~IDamageSource() = default;
	virtual void getDamage() const = 0;
};