// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_PLAYMODE_SET_PLAYER_GAME_TAG_TASK_HPP
#define ROSETTASTONE_PLAYMODE_SET_PLAYER_GAME_TAG_TASK_HPP

#include <Rosetta/PlayMode/Tasks/ITask.hpp>

namespace RosettaStone::PlayMode::SimpleTasks
{
//!
//! \brief SetGameTagTask class.
//!
//! This class represents the task for setting game tag to player.
//!
class SetPlayerGameTagTask : public ITask
{
 public:
    //! Constructs task with given \p tag and \p value.
    //! \param tag A game tag to set.
    //! \param value The value of game tag to set.
    explicit SetPlayerGameTagTask(GameTag tag, int value);

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player* player) override;

    //! Internal method of Clone().
    //! \return The cloned task.
    std::unique_ptr<ITask> CloneImpl() override;

    GameTag m_gameTag = GameTag::INVALID;
    int m_value = 0;
};
}  // namespace RosettaStone::PlayMode::SimpleTasks

#endif  // ROSETTASTONE_PLAYMODE_SET_PLAYER_GAME_TAG_TASK_HPP
