// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Battlegrounds/Models/Minion.hpp>

#include <utility>

namespace RosettaStone::Battlegrounds
{
Minion::Minion(Card card, int poolIdx)
    : m_card(std::move(card)),
      m_poolIdx(poolIdx),
      m_attack(m_card.GetAttack()),
      m_health(m_card.GetHealth())
{
    // Do nothing
}

int Minion::GetPoolIndex() const
{
    return m_poolIdx;
}

Race Minion::GetRace() const
{
    return m_card.GetRace();
}

ZoneType Minion::GetZoneType() const
{
    return m_zoneType;
}

void Minion::SetZoneType(ZoneType type)
{
    m_zoneType = type;
}

int Minion::GetZonePosition() const
{
    return m_zonePos;
}

void Minion::SetZonePosition(int pos)
{
    m_zonePos = pos;
}

int Minion::GetTier() const
{
    return m_card.GetTier();
}

int Minion::GetAttack() const
{
    return m_attack;
}

int Minion::GetHealth() const
{
    return m_health;
}

bool Minion::HasTaunt() const
{
    if (const auto iter = m_card.gameTags.find(GameTag::TAUNT);
        iter != m_card.gameTags.end())
    {
        return iter->second;
    }

    return false;
}

void Minion::TakeDamage(Minion& source)
{
    m_health -= source.GetAttack();
    if (m_health <= 0)
    {
        m_isDestroyed = true;
    }
}
}  // namespace RosettaStone::Battlegrounds
