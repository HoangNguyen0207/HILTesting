#pragma once

#include <QObject>
#include "store.h"
using namespace flux_qt;

class MainStore final : public QObject, public Store
{
        Q_OBJECT
        Q_PROPERTY(QString loadedProcessFilePath READ loadedProcessFilePath WRITE setLoadedProcessFilePath NOTIFY loadedProcessFilePathChanged)
        Q_PROPERTY(bool laserTrackerDialogShowFlag READ laserTrackerDialogShowFlag WRITE setLaserTrackerDialogShowFlag NOTIFY laserTrackerDialogShowFlagChanged)

        Q_PROPERTY(bool fmsEnableFlag READ fmsEnableFlag WRITE setFmsEnableFlag NOTIFY fmsEnableFlagChanged)
        Q_PROPERTY(bool fmsControlFlag READ fmsControlFlag WRITE setFmsControlFlag NOTIFY fmsControlFlagChanged)
        Q_PROPERTY(bool fmsHomingFlag READ fmsHomingFlag WRITE setFmsHomingFlag NOTIFY fmsHomingFlagChanged)
        Q_PROPERTY(bool fmsMoveAbsModeFlag READ fmsMoveAbsModeFlag WRITE setFmsMoveAbsModeFlag NOTIFY fmsMoveAbsModeFlagChanged)
        Q_PROPERTY(double fmsTxPos READ fmsTxPos WRITE setFmsTxPos NOTIFY fmsTxPosChanged)
        Q_PROPERTY(double fmsTyPos READ fmsTyPos WRITE setFmsTyPos NOTIFY fmsTyPosChanged)
        Q_PROPERTY(double fmsTzPos READ fmsTzPos WRITE setFmsTzPos NOTIFY fmsTzPosChanged)
        Q_PROPERTY(double fmsRxPos READ fmsRxPos WRITE setFmsRxPos NOTIFY fmsRxPosChanged)
        Q_PROPERTY(double fmsRyPos READ fmsRyPos WRITE setFmsRyPos NOTIFY fmsRyPosChanged)
        Q_PROPERTY(double fmsRzPos READ fmsRzPos WRITE setFmsRzPos NOTIFY fmsRzPosChanged)
        Q_PROPERTY(double fmsTxVel READ fmsTxVel WRITE setFmsTxVel NOTIFY fmsTxVelChanged)
        Q_PROPERTY(double fmsTyVel READ fmsTyVel WRITE setFmsTyVel NOTIFY fmsTyVelChanged)
        Q_PROPERTY(double fmsTzVel READ fmsTzVel WRITE setFmsTzVel NOTIFY fmsTzVelChanged)
        Q_PROPERTY(double fmsRxVel READ fmsRxVel WRITE setFmsRxVel NOTIFY fmsRxVelChanged)
        Q_PROPERTY(double fmsRyVel READ fmsRyVel WRITE setFmsRyVel NOTIFY fmsRyVelChanged)
        Q_PROPERTY(double fmsRzVel READ fmsRzVel WRITE setFmsRzVel NOTIFY fmsRzVelChanged)
        Q_PROPERTY(double fmsTxAcc READ fmsTxAcc WRITE setFmsTxAcc NOTIFY fmsTxAccChanged)
        Q_PROPERTY(double fmsTyAcc READ fmsTyAcc WRITE setFmsTyAcc NOTIFY fmsTyAccChanged)
        Q_PROPERTY(double fmsTzAcc READ fmsTzAcc WRITE setFmsTzAcc NOTIFY fmsTzAccChanged)
        Q_PROPERTY(double fmsRxAcc READ fmsRxAcc WRITE setFmsRxAcc NOTIFY fmsRxAccChanged)
        Q_PROPERTY(double fmsRyAcc READ fmsRyAcc WRITE setFmsRyAcc NOTIFY fmsRyAccChanged)
        Q_PROPERTY(double fmsRzAcc READ fmsRzAcc WRITE setFmsRzAcc NOTIFY fmsRzAccChanged)

        Q_PROPERTY(bool tmsEnableFlag READ tmsEnableFlag WRITE setTmsEnableFlag NOTIFY tmsEnableFlagChanged)
        Q_PROPERTY(bool tmsControlFlag READ tmsControlFlag WRITE setTmsControlFlag NOTIFY tmsControlFlagChanged)
        Q_PROPERTY(bool tmsHomingFlag READ tmsHomingFlag WRITE setTmsHomingFlag NOTIFY tmsHomingFlagChanged)
        Q_PROPERTY(bool tmsMoveAbsModeFlag READ tmsMoveAbsModeFlag WRITE setTmsMoveAbsModeFlag NOTIFY tmsMoveAbsModeFlagChanged)
        Q_PROPERTY(double tmsTxPos READ tmsTxPos WRITE setTmsTxPos NOTIFY tmsTxPosChanged)
        Q_PROPERTY(double tmsTyPos READ tmsTyPos WRITE setTmsTyPos NOTIFY tmsTyPosChanged)
        Q_PROPERTY(double tmsRxPos READ tmsRxPos WRITE setTmsRxPos NOTIFY tmsRxPosChanged)
        Q_PROPERTY(double tmsRyPos READ tmsRyPos WRITE setTmsRyPos NOTIFY tmsRyPosChanged)
        Q_PROPERTY(double tmsTxVel READ tmsTxVel WRITE setTmsTxVel NOTIFY tmsTxVelChanged)
        Q_PROPERTY(double tmsTyVel READ tmsTyVel WRITE setTmsTyVel NOTIFY tmsTyVelChanged)
        Q_PROPERTY(double tmsRxVel READ tmsRxVel WRITE setTmsRxVel NOTIFY tmsRxVelChanged)
        Q_PROPERTY(double tmsRyVel READ tmsRyVel WRITE setTmsRyVel NOTIFY tmsRyVelChanged)
        Q_PROPERTY(double tmsTxAcc READ tmsTxAcc WRITE setTmsTxAcc NOTIFY tmsTxAccChanged)
        Q_PROPERTY(double tmsTyAcc READ tmsTyAcc WRITE setTmsTyAcc NOTIFY tmsTyAccChanged)
        Q_PROPERTY(double tmsRxAcc READ tmsRxAcc WRITE setTmsRxAcc NOTIFY tmsRxAccChanged)
        Q_PROPERTY(double tmsRyAcc READ tmsRyAcc WRITE setTmsRyAcc NOTIFY tmsRyAccChanged)

        Q_PROPERTY(bool plotProcessFlag READ plotProcessFlag WRITE setPlotProcessFlag NOTIFY plotProcessFlagChanged)


    public:
        ~MainStore() override;
        static MainStore* getInstance()
        {
            static MainStore self;
            return &self;
        }
        void process(const QSharedPointer<Action> &action) override;
        QString loadedProcessFilePath() const;
        bool laserTrackerDialogShowFlag() const;

        bool fmsEnableFlag() const;
        bool fmsControlFlag() const;
        bool fmsHomingFlag() const;
        bool fmsMoveAbsModeFlag() const;
        double fmsTxPos() const;
        double fmsTyPos() const;
        double fmsTzPos() const;
        double fmsRxPos() const;
        double fmsRyPos() const;
        double fmsRzPos() const;
        double fmsTxVel() const;
        double fmsTyVel() const;
        double fmsTzVel() const;
        double fmsRxVel() const;
        double fmsRyVel() const;
        double fmsRzVel() const;
        double fmsTxAcc() const;
        double fmsTyAcc() const;
        double fmsTzAcc() const;
        double fmsRxAcc() const;
        double fmsRyAcc() const;
        double fmsRzAcc() const;

        bool tmsEnableFlag() const;
        bool tmsControlFlag() const;
        bool tmsHomingFlag() const;
        bool tmsMoveAbsModeFlag() const;
        double tmsTxPos() const;
        double tmsTyPos() const;
        double tmsTzPos() const;
        double tmsRxPos() const;
        double tmsRyPos() const;
        double tmsTxVel() const;
        double tmsTyVel() const;
        double tmsRxVel() const;
        double tmsRyVel() const;
        double tmsTxAcc() const;
        double tmsTyAcc() const;
        double tmsRxAcc() const;
        double tmsRyAcc() const;

        bool plotProcessFlag() const;

    public slots:
        void setLoadedProcessFilePath(QString loadedProcessFilePath);
        void setLaserTrackerDialogShowFlag(bool laserTrackerDialogShowFlag);
        void setFmsEnableFlag(bool fmsEnableFlag);
        void setFmsControlFlag(bool fmsControlFlag);
        void setFmsHomingFlag(bool fmsHomingFlag);
        void setFmsMoveAbsModeFlag(bool fmsMoveAbsModeFlag);
        void setFmsTxPos(double fmsTxPos);
        void setFmsTyPos(double fmsTyPos);
        void setFmsTzPos(double fmsTzPos);
        void setFmsRxPos(double fmsRxPos);
        void setFmsRyPos(double fmsRyPos);
        void setFmsRzPos(double fmsRzPos);
        void setFmsTxVel(double fmsTxVel);
        void setFmsTyVel(double fmsTyVel);
        void setFmsTzVel(double fmsTzVel);
        void setFmsRxVel(double fmsRxVel);
        void setFmsRyVel(double fmsRyVel);
        void setFmsRzVel(double fmsRzVel);
        void setFmsTxAcc(double fmsTxAcc);
        void setFmsTyAcc(double fmsTyAcc);
        void setFmsTzAcc(double fmsTzAcc);
        void setFmsRxAcc(double fmsRxAcc);
        void setFmsRyAcc(double fmsRyAcc);
        void setFmsRzAcc(double fmsRzAcc);

        void setTmsEnableFlag(bool tmsEnableFlag);
        void setTmsControlFlag(bool tmsControlFlag);
        void setTmsHomingFlag(bool tmsHomingFlag);
        void setTmsMoveAbsModeFlag(bool tmsMoveAbsModeFlag);
        void setTmsTxPos(double tmsTxPos);
        void setTmsTyPos(double tmsTyPos);
        void setTmsRxPos(double tmsRxPos);
        void setTmsRyPos(double tmsRyPos);
        void setTmsTxVel(double tmsTxVel);
        void setTmsTyVel(double tmsTyVel);
        void setTmsRxVel(double tmsRxVel);
        void setTmsRyVel(double tmsRyVel);
        void setTmsTxAcc(double tmsTxAcc);
        void setTmsTyAcc(double tmsTyAcc);
        void setTmsRxAcc(double tmsRxAcc);
        void setTmsRyAcc(double tmsRyAcc);

        void setPlotProcessFlag(bool plotProcessFlag);

    signals:
        void loadedProcessFilePathChanged(QString loadedProcessFilePath);
        void laserTrackerDialogShowFlagChanged(bool laserTrackerDialogShowFlag);
        void fmsEnableFlagChanged(bool fmsEnableFlag);
        void fmsControlFlagChanged(bool fmsControlFlag);
        void fmsHomingFlagChanged(bool fmsHomingFlag);
        void fmsMoveAbsModeFlagChanged(bool fmsMoveAbsModeFlag);
        void fmsTxPosChanged(double fmsTxPos);
        void fmsTyPosChanged(double fmsTyPos);
        void fmsTzPosChanged(double fmsTzPos);
        void fmsRxPosChanged(double fmsRxPos);
        void fmsRyPosChanged(double fmsRyPos);
        void fmsRzPosChanged(double fmsRzPos);
        void fmsTxVelChanged(double fmsTxVel);
        void fmsTyVelChanged(double fmsTyVel);
        void fmsTzVelChanged(double fmsTzVel);
        void fmsRxVelChanged(double fmsRxVel);
        void fmsRyVelChanged(double fmsRyVel);
        void fmsRzVelChanged(double fmsRzVel);
        void fmsTxAccChanged(double fmsTxAcc);
        void fmsTyAccChanged(double fmsTyAcc);
        void fmsTzAccChanged(double fmsTzAcc);
        void fmsRxAccChanged(double fmsRxAcc);
        void fmsRyAccChanged(double fmsRyAcc);
        void fmsRzAccChanged(double fmsRzAcc);

        void tmsEnableFlagChanged(bool tmsEnableFlag);
        void tmsControlFlagChanged(bool tmsControlFlag);
        void tmsHomingFlagChanged(bool tmsHomingFlag);
        void tmsMoveAbsModeFlagChanged(bool tmsMoveAbsModeFlag);
        void tmsTxPosChanged(double tmsTxPos);
        void tmsTyPosChanged(double tmsTyPos);
        void tmsRxPosChanged(double tmsRxPos);
        void tmsRyPosChanged(double tmsRyPos);
        void tmsTxVelChanged(double tmsTxVel);
        void tmsTyVelChanged(double tmsTyVel);
        void tmsRxVelChanged(double tmsRxVel);
        void tmsRyVelChanged(double tmsRyVel);
        void tmsTxAccChanged(double tmsTxAcc);
        void tmsTyAccChanged(double tmsTyAcc);
        void tmsRxAccChanged(double tmsRxAcc);
        void tmsRyAccChanged(double tmsRyAcc);

        void plotProcessFlagChanged(bool plotProcessFlag);

    private:
        explicit MainStore(QObject* parent = nullptr);

        QString mLoadedProcessFilePath;
        bool mLaserTrackerDialogShowFlag;
        bool m_fmsEnableFlag;
        bool m_fmsControlFlag;
        bool m_fmsHomingFlag;
        bool m_fmsMoveAbsModeFlag;
        double m_fmsTxPos;
        double m_fmsTyPos;
        double m_fmsTzPos;
        double m_fmsRxPos;
        double m_fmsRyPos;
        double m_fmsRzPos;
        double m_fmsTxVel;
        double m_fmsTyVel;
        double m_fmsTzVel;
        double m_fmsRxVel;
        double m_fmsRyVel;
        double m_fmsRzVel;
        double m_fmsTxAcc;
        double m_fmsTyAcc;
        double m_fmsTzAcc;
        double m_fmsRxAcc;
        double m_fmsRyAcc;
        double m_fmsRzAcc;

        bool m_tmsEnableFlag;
        bool m_tmsControlFlag;
        bool m_tmsHomingFlag;
        bool m_tmsMoveAbsModeFlag;
        double m_tmsTxPos;
        double m_tmsTyPos;
        double m_tmsRxPos;
        double m_tmsRyPos;
        double m_tmsTxVel;
        double m_tmsTyVel;
        double m_tmsRxVel;
        double m_tmsRyVel;
        double m_tmsTxAcc;
        double m_tmsTyAcc;
        double m_tmsRxAcc;
        double m_tmsRyAcc;

        bool m_plotProcessFlag;
};

