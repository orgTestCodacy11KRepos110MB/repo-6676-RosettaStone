#ifndef HEARTHSTONEPP_ENTITY_H
#define HEARTHSTONEPP_ENTITY_H

#include <Cards/Card.h>

#include <map>

namespace Hearthstonepp
{
struct Card;
class GameTag;

//!
//! \brief Abstract entity structure that stores card data.
//!
//! This structure is base structure of all data-holding/action-performing/
//! visible or invisible objects in a Hearthstone++.
//! An entity is defined as a collection of properties, called GameTags.
//!
struct Entity
{
    //! Default constructor.
    Entity() = default;

    //! Constructs entity with given \p pCard.
    //! \param pCard A pointer to the card.
    Entity(const Card* pCard);

    //! Destructor.
    virtual ~Entity() = default;

    const Card* card = nullptr;

    std::map<GameTag, int> gameTags;

};
}

#endif