#include "mainstore.h"
#include "flux/action/actiontypes.h"
#include "action.h"

void MainStore::process(const QSharedPointer<Action> &action)
{
    switch(action->getType<ActionType>())
    {
        case ActionType::LaserTrackerDialogShowFlagChanged:
        {
            setLaserTrackerDialogShowFlag(action->getPayload<bool>());
            break;
        }
        default: break;
    }
}

QString MainStore::loadedProcessFilePath() const
{
    return mLoadedProcessFilePath;
}

bool MainStore::laserTrackerDialogShowFlag() const
{
    return mLaserTrackerDialogShowFlag;
}

bool MainStore::fmsEnableFlag() const
{
    return m_fmsEnableFlag;
}

bool MainStore::fmsControlFlag() const
{
    return m_fmsControlFlag;
}

bool MainStore::fmsHomingFlag() const
{
    return m_fmsHomingFlag;
}

bool MainStore::fmsMoveAbsModeFlag() const
{
    return m_fmsMoveAbsModeFlag;
}

double MainStore::fmsTxPos() const
{
    return m_fmsTxPos;
}

double MainStore::fmsTyPos() const
{
    return m_fmsTyPos;
}

double MainStore::fmsTzPos() const
{
    return m_fmsTzPos;
}

double MainStore::fmsRxPos() const
{
    return m_fmsRxPos;
}

double MainStore::fmsRyPos() const
{
    return m_fmsRyPos;
}

double MainStore::fmsRzPos() const
{
    return m_fmsRzPos;
}

double MainStore::fmsTxVel() const
{
    return m_fmsTxVel;
}

double MainStore::fmsTyVel() const
{
    return m_fmsTyVel;
}

double MainStore::fmsTzVel() const
{
    return m_fmsTzVel;
}

double MainStore::fmsRxVel() const
{
    return m_fmsRxVel;
}

double MainStore::fmsRyVel() const
{
    return m_fmsRyVel;
}

double MainStore::fmsRzVel() const
{
    return m_fmsRzVel;
}

double MainStore::fmsTxAcc() const
{
    return m_fmsTxAcc;
}

double MainStore::fmsTyAcc() const
{
    return m_fmsTyAcc;
}

double MainStore::fmsTzAcc() const
{
    return m_fmsTzAcc;
}

double MainStore::fmsRxAcc() const
{
    return m_fmsRxAcc;
}

double MainStore::fmsRyAcc() const
{
    return m_fmsRyAcc;
}

double MainStore::fmsRzAcc() const
{
    return m_fmsRzAcc;
}

bool MainStore::tmsEnableFlag() const
{
    return m_tmsEnableFlag;
}

bool MainStore::tmsControlFlag() const
{
    return m_tmsControlFlag;
}

bool MainStore::tmsHomingFlag() const
{
    return m_tmsHomingFlag;
}

bool MainStore::tmsMoveAbsModeFlag() const
{
    return m_tmsMoveAbsModeFlag;
}

double MainStore::tmsTxPos() const
{
    return m_tmsTxPos;
}

double MainStore::tmsTyPos() const
{
    return m_tmsTyPos;
}

double MainStore::tmsRxPos() const
{
    return m_tmsRxPos;
}

double MainStore::tmsRyPos() const
{
    return m_tmsRyPos;
}

double MainStore::tmsTxVel() const
{
    return m_tmsTxVel;
}

double MainStore::tmsTyVel() const
{
    return m_tmsTyVel;
}

double MainStore::tmsRxVel() const
{
    return m_tmsRxVel;
}

double MainStore::tmsRyVel() const
{
    return m_tmsRyVel;
}

double MainStore::tmsTxAcc() const
{
    return m_tmsTxAcc;
}

double MainStore::tmsTyAcc() const
{
    return m_tmsTyAcc;
}

double MainStore::tmsRxAcc() const
{
    return m_tmsRxAcc;
}

double MainStore::tmsRyAcc() const
{
    return m_tmsRyAcc;
}

bool MainStore::plotProcessFlag() const
{
    return m_plotProcessFlag;
}

void MainStore::setLoadedProcessFilePath(QString loadedProcessFilePath)
{
    if (mLoadedProcessFilePath == loadedProcessFilePath)
        return;

    mLoadedProcessFilePath = loadedProcessFilePath;
    emit loadedProcessFilePathChanged(mLoadedProcessFilePath);
}

void MainStore::setLaserTrackerDialogShowFlag(bool laserTrackerDialogShowFlag)
{
    if (mLaserTrackerDialogShowFlag == laserTrackerDialogShowFlag)
        return;

    mLaserTrackerDialogShowFlag = laserTrackerDialogShowFlag;
    emit laserTrackerDialogShowFlagChanged(mLaserTrackerDialogShowFlag);
}

void MainStore::setFmsEnableFlag(bool fmsEnableFlag)
{
    if (m_fmsEnableFlag == fmsEnableFlag)
        return;

    m_fmsEnableFlag = fmsEnableFlag;
    emit fmsEnableFlagChanged(m_fmsEnableFlag);
}

void MainStore::setFmsControlFlag(bool fmsControlFlag)
{
    if (m_fmsControlFlag == fmsControlFlag)
        return;

    m_fmsControlFlag = fmsControlFlag;
    emit fmsControlFlagChanged(m_fmsControlFlag);
}

void MainStore::setFmsHomingFlag(bool fmsHomingFlag)
{
    if (m_fmsHomingFlag == fmsHomingFlag)
        return;

    m_fmsHomingFlag = fmsHomingFlag;
    emit fmsHomingFlagChanged(m_fmsHomingFlag);
}

void MainStore::setFmsMoveAbsModeFlag(bool fmsMoveAbsModeFlag)
{
    if (m_fmsMoveAbsModeFlag == fmsMoveAbsModeFlag)
        return;

    m_fmsMoveAbsModeFlag = fmsMoveAbsModeFlag;
    emit fmsMoveAbsModeFlagChanged(m_fmsMoveAbsModeFlag);
}

void MainStore::setFmsTxPos(double fmsTxPos)
{
    if (qFuzzyCompare(m_fmsTxPos, fmsTxPos))
        return;

    m_fmsTxPos = fmsTxPos;
    emit fmsTxPosChanged(m_fmsTxPos);
}

void MainStore::setFmsTyPos(double fmsTyPos)
{
    if (qFuzzyCompare(m_fmsTyPos, fmsTyPos))
        return;

    m_fmsTyPos = fmsTyPos;
    emit fmsTyPosChanged(m_fmsTyPos);
}

void MainStore::setFmsTzPos(double fmsTzPos)
{
    if (qFuzzyCompare(m_fmsTzPos, fmsTzPos))
        return;

    m_fmsTzPos = fmsTzPos;
    emit fmsTzPosChanged(m_fmsTzPos);
}

void MainStore::setFmsRxPos(double fmsRxPos)
{
    if (qFuzzyCompare(m_fmsRxPos, fmsRxPos))
        return;

    m_fmsRxPos = fmsRxPos;
    emit fmsRxPosChanged(m_fmsRxPos);
}

void MainStore::setFmsRyPos(double fmsRyPos)
{
    if (qFuzzyCompare(m_fmsRyPos, fmsRyPos))
        return;

    m_fmsRyPos = fmsRyPos;
    emit fmsRyPosChanged(m_fmsRyPos);
}

void MainStore::setFmsRzPos(double fmsRzPos)
{
    if (qFuzzyCompare(m_fmsRzPos, fmsRzPos))
        return;

    m_fmsRzPos = fmsRzPos;
    emit fmsRzPosChanged(m_fmsRzPos);
}

void MainStore::setFmsTxVel(double fmsTxVel)
{
    if (qFuzzyCompare(m_fmsTxVel, fmsTxVel))
        return;

    m_fmsTxVel = fmsTxVel;
    emit fmsTxVelChanged(m_fmsTxVel);
}

void MainStore::setFmsTyVel(double fmsTyVel)
{
    if (qFuzzyCompare(m_fmsTyVel, fmsTyVel))
        return;

    m_fmsTyVel = fmsTyVel;
    emit fmsTyVelChanged(m_fmsTyVel);
}

void MainStore::setFmsTzVel(double fmsTzVel)
{
    if (qFuzzyCompare(m_fmsTzVel, fmsTzVel))
        return;

    m_fmsTzVel = fmsTzVel;
    emit fmsTzVelChanged(m_fmsTzVel);
}

void MainStore::setFmsRxVel(double fmsRxVel)
{
    if (qFuzzyCompare(m_fmsRxVel, fmsRxVel))
        return;

    m_fmsRxVel = fmsRxVel;
    emit fmsRxVelChanged(m_fmsRxVel);
}

void MainStore::setFmsRyVel(double fmsRyVel)
{
    if (qFuzzyCompare(m_fmsRyVel, fmsRyVel))
        return;

    m_fmsRyVel = fmsRyVel;
    emit fmsRyVelChanged(m_fmsRyVel);
}

void MainStore::setFmsRzVel(double fmsRzVel)
{
    if (qFuzzyCompare(m_fmsRzVel, fmsRzVel))
        return;

    m_fmsRzVel = fmsRzVel;
    emit fmsRzVelChanged(m_fmsRzVel);
}

void MainStore::setFmsTxAcc(double fmsTxAcc)
{
    if (qFuzzyCompare(m_fmsTxAcc, fmsTxAcc))
        return;

    m_fmsTxAcc = fmsTxAcc;
    emit fmsTxAccChanged(m_fmsTxAcc);
}

void MainStore::setFmsTyAcc(double fmsTyAcc)
{
    if (qFuzzyCompare(m_fmsTyAcc, fmsTyAcc))
        return;

    m_fmsTyAcc = fmsTyAcc;
    emit fmsTyAccChanged(m_fmsTyAcc);
}

void MainStore::setFmsTzAcc(double fmsTzAcc)
{
    if (qFuzzyCompare(m_fmsTzAcc, fmsTzAcc))
        return;

    m_fmsTzAcc = fmsTzAcc;
    emit fmsTzAccChanged(m_fmsTzAcc);
}

void MainStore::setFmsRxAcc(double fmsRxAcc)
{
    if (qFuzzyCompare(m_fmsRxAcc, fmsRxAcc))
        return;

    m_fmsRxAcc = fmsRxAcc;
    emit fmsRxAccChanged(m_fmsRxAcc);
}

void MainStore::setFmsRyAcc(double fmsRyAcc)
{
    if (qFuzzyCompare(m_fmsRyAcc, fmsRyAcc))
        return;

    m_fmsRyAcc = fmsRyAcc;
    emit fmsRyAccChanged(m_fmsRyAcc);
}

void MainStore::setFmsRzAcc(double fmsRzAcc)
{
    if (qFuzzyCompare(m_fmsRzAcc, fmsRzAcc))
        return;

    m_fmsRzAcc = fmsRzAcc;
    emit fmsRzAccChanged(m_fmsRzAcc);
}

void MainStore::setTmsEnableFlag(bool tmsEnableFlag)
{
    if (m_tmsEnableFlag == tmsEnableFlag)
        return;

    m_tmsEnableFlag = tmsEnableFlag;
    emit tmsEnableFlagChanged(m_tmsEnableFlag);
}

void MainStore::setTmsControlFlag(bool tmsControlFlag)
{
    if (m_tmsControlFlag == tmsControlFlag)
        return;

    m_tmsControlFlag = tmsControlFlag;
    emit tmsControlFlagChanged(m_tmsControlFlag);
}

void MainStore::setTmsHomingFlag(bool tmsHomingFlag)
{
    if (m_tmsHomingFlag == tmsHomingFlag)
        return;

    m_tmsHomingFlag = tmsHomingFlag;
    emit tmsHomingFlagChanged(m_tmsHomingFlag);
}

void MainStore::setTmsMoveAbsModeFlag(bool tmsMoveAbsModeFlag)
{
    if (m_tmsMoveAbsModeFlag == tmsMoveAbsModeFlag)
        return;

    m_tmsMoveAbsModeFlag = tmsMoveAbsModeFlag;
    emit tmsMoveAbsModeFlagChanged(m_tmsMoveAbsModeFlag);
}

void MainStore::setTmsTxPos(double tmsTxPos)
{
    if (qFuzzyCompare(m_tmsTxPos, tmsTxPos))
        return;

    m_tmsTxPos = tmsTxPos;
    emit tmsTxPosChanged(m_tmsTxPos);
}

void MainStore::setTmsTyPos(double tmsTyPos)
{
    if (qFuzzyCompare(m_tmsTyPos, tmsTyPos))
        return;

    m_tmsTyPos = tmsTyPos;
    emit tmsTyPosChanged(m_tmsTyPos);
}

void MainStore::setTmsRxPos(double tmsRxPos)
{
    if (qFuzzyCompare(m_tmsRxPos, tmsRxPos))
        return;

    m_tmsRxPos = tmsRxPos;
    emit tmsRxPosChanged(m_tmsRxPos);
}

void MainStore::setTmsRyPos(double tmsRyPos)
{
    if (qFuzzyCompare(m_tmsRyPos, tmsRyPos))
        return;

    m_tmsRyPos = tmsRyPos;
    emit tmsRyPosChanged(m_tmsRyPos);
}

void MainStore::setTmsTxVel(double tmsTxVel)
{
    if (qFuzzyCompare(m_tmsTxVel, tmsTxVel))
        return;

    m_tmsTxVel = tmsTxVel;
    emit tmsTxVelChanged(m_tmsTxVel);
}

void MainStore::setTmsTyVel(double tmsTyVel)
{
    if (qFuzzyCompare(m_tmsTyVel, tmsTyVel))
        return;

    m_tmsTyVel = tmsTyVel;
    emit tmsTyVelChanged(m_tmsTyVel);
}

void MainStore::setTmsRxVel(double tmsRxVel)
{
    if (qFuzzyCompare(m_tmsRxVel, tmsRxVel))
        return;

    m_tmsRxVel = tmsRxVel;
    emit tmsRxVelChanged(m_tmsRxVel);
}

void MainStore::setTmsRyVel(double tmsRyVel)
{
    if (qFuzzyCompare(m_tmsRyVel, tmsRyVel))
        return;

    m_tmsRyVel = tmsRyVel;
    emit tmsRyVelChanged(m_tmsRyVel);
}

void MainStore::setTmsTxAcc(double tmsTxAcc)
{
    if (qFuzzyCompare(m_tmsTxAcc, tmsTxAcc))
        return;

    m_tmsTxAcc = tmsTxAcc;
    emit tmsTxAccChanged(m_tmsTxAcc);
}

void MainStore::setTmsTyAcc(double tmsTyAcc)
{
    if (qFuzzyCompare(m_tmsTyAcc, tmsTyAcc))
        return;

    m_tmsTyAcc = tmsTyAcc;
    emit tmsTyAccChanged(m_tmsTyAcc);
}

void MainStore::setTmsRxAcc(double tmsRxAcc)
{
    if (qFuzzyCompare(m_tmsRxAcc, tmsRxAcc))
        return;

    m_tmsRxAcc = tmsRxAcc;
    emit tmsRxAccChanged(m_tmsRxAcc);
}

void MainStore::setTmsRyAcc(double tmsRyAcc)
{
    if (qFuzzyCompare(m_tmsRyAcc, tmsRyAcc))
        return;

    m_tmsRyAcc = tmsRyAcc;
    emit tmsRyAccChanged(m_tmsRyAcc);
}

void MainStore::setPlotProcessFlag(bool plotProcessFlag)
{
    if (m_plotProcessFlag == plotProcessFlag)
        return;

    m_plotProcessFlag = plotProcessFlag;
    emit plotProcessFlagChanged(m_plotProcessFlag);
}

MainStore::MainStore(QObject* parent) : QObject(parent)
{

}

MainStore::~MainStore()
{

}

