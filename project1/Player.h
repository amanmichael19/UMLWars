/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#pragma once
#include <memory>
#include "GameObject.h"
#include "Timer.h"


class CRedPen;


 /**
  * class implementing player
  */
class CPlayer : public CGameObject
{
	public:
		/// constructor
		CPlayer(CGame* game);

		/// Default constructor disabled
		CPlayer() = delete;

		/// default copy constructor disabled
		CPlayer(const CPlayer&) = delete;

		/** draws game objects
		* \param graphics
		*/
		virtual void Draw(Gdiplus::Graphics* graphics) override;

		void GetAPen();

		bool IfGetPen();

		/// compute angle
		/// \param mouseX
		/// \param mouseY
		void OnMouseMove(double mouseX, double mouseY);

		/// fire pen
		/// \param mouseX
		/// \param mouseY
		void OnLeftClick(double mouseX, double mouseY);

		/** Accept a visitor
		* \param visitor
		*/
		virtual void Accept(CGameObjectVisitor* visitor) { visitor->VisitPlayer(this); };

		virtual void Update(double elapsed) {};

	private:
		/// player image
		std::unique_ptr<Gdiplus::Bitmap> mPlayerImage;
		/// pen handler
		std::shared_ptr<CRedPen> mPenOnHand;
		bool mIsPenOnHand;
		/// angle of rotation
		double mAngle = 0.0;
		
		CGame* mGame;

		std::shared_ptr<CTimer>	 mTimer;

};
















