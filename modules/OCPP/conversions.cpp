// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include <conversions.hpp>
#include <ocpp_conversions.hpp>

namespace module {
namespace conversions {

ocpp::FirmwareStatusNotification
to_ocpp_firmware_status_notification(const types::system::FirmwareUpdateStatusEnum status) {
    switch (status) {
    case types::system::FirmwareUpdateStatusEnum::Downloaded:
        return ocpp::FirmwareStatusNotification::Downloaded;
    case types::system::FirmwareUpdateStatusEnum::DownloadFailed:
        return ocpp::FirmwareStatusNotification::DownloadFailed;
    case types::system::FirmwareUpdateStatusEnum::Downloading:
        return ocpp::FirmwareStatusNotification::Downloading;
    case types::system::FirmwareUpdateStatusEnum::DownloadScheduled:
        return ocpp::FirmwareStatusNotification::DownloadScheduled;
    case types::system::FirmwareUpdateStatusEnum::DownloadPaused:
        return ocpp::FirmwareStatusNotification::DownloadPaused;
    case types::system::FirmwareUpdateStatusEnum::Idle:
        return ocpp::FirmwareStatusNotification::Idle;
    case types::system::FirmwareUpdateStatusEnum::InstallationFailed:
        return ocpp::FirmwareStatusNotification::InstallationFailed;
    case types::system::FirmwareUpdateStatusEnum::Installing:
        return ocpp::FirmwareStatusNotification::Installing;
    case types::system::FirmwareUpdateStatusEnum::Installed:
        return ocpp::FirmwareStatusNotification::Installed;
    case types::system::FirmwareUpdateStatusEnum::InstallRebooting:
        return ocpp::FirmwareStatusNotification::InstallRebooting;
    case types::system::FirmwareUpdateStatusEnum::InstallScheduled:
        return ocpp::FirmwareStatusNotification::InstallScheduled;
    case types::system::FirmwareUpdateStatusEnum::InstallVerificationFailed:
        return ocpp::FirmwareStatusNotification::InstallVerificationFailed;
    case types::system::FirmwareUpdateStatusEnum::InvalidSignature:
        return ocpp::FirmwareStatusNotification::InvalidSignature;
    case types::system::FirmwareUpdateStatusEnum::SignatureVerified:
        return ocpp::FirmwareStatusNotification::SignatureVerified;
    }
    throw std::out_of_range("Could not convert FirmwareUpdateStatusEnum to FirmwareStatusNotification");
}

ocpp::SessionStartedReason to_ocpp_session_started_reason(const types::evse_manager::StartSessionReason reason) {
    switch (reason) {
    case types::evse_manager::StartSessionReason::EVConnected:
        return ocpp::SessionStartedReason::EVConnected;
    case types::evse_manager::StartSessionReason::Authorized:
        return ocpp::SessionStartedReason::Authorized;
    }
    throw std::out_of_range("Could not convert types::evse_manager::StartSessionReason to ocpp::SessionStartedReason");
}

ocpp::v16::DataTransferStatus to_ocpp_data_transfer_status(const types::ocpp::DataTransferStatus status) {
    switch (status) {
    case types::ocpp::DataTransferStatus::Accepted:
        return ocpp::v16::DataTransferStatus::Accepted;
    case types::ocpp::DataTransferStatus::Rejected:
        return ocpp::v16::DataTransferStatus::Rejected;
    case types::ocpp::DataTransferStatus::UnknownMessageId:
        return ocpp::v16::DataTransferStatus::UnknownMessageId;
    case types::ocpp::DataTransferStatus::UnknownVendorId:
        return ocpp::v16::DataTransferStatus::UnknownVendorId;
    case types::ocpp::DataTransferStatus::Offline:
        return ocpp::v16::DataTransferStatus::UnknownVendorId;
    }
    return ocpp::v16::DataTransferStatus::UnknownVendorId;
}

ocpp::v16::Reason to_ocpp_reason(const types::evse_manager::StopTransactionReason reason) {
    switch (reason) {
    case types::evse_manager::StopTransactionReason::EmergencyStop:
        return ocpp::v16::Reason::EmergencyStop;
    case types::evse_manager::StopTransactionReason::EVDisconnected:
        return ocpp::v16::Reason::EVDisconnected;
    case types::evse_manager::StopTransactionReason::HardReset:
        return ocpp::v16::Reason::HardReset;
    case types::evse_manager::StopTransactionReason::Local:
        return ocpp::v16::Reason::Local;
    case types::evse_manager::StopTransactionReason::PowerLoss:
        return ocpp::v16::Reason::PowerLoss;
    case types::evse_manager::StopTransactionReason::Reboot:
        return ocpp::v16::Reason::Reboot;
    case types::evse_manager::StopTransactionReason::Remote:
        return ocpp::v16::Reason::Remote;
    case types::evse_manager::StopTransactionReason::SoftReset:
        return ocpp::v16::Reason::SoftReset;
    case types::evse_manager::StopTransactionReason::UnlockCommand:
        return ocpp::v16::Reason::UnlockCommand;
    case types::evse_manager::StopTransactionReason::DeAuthorized:
        return ocpp::v16::Reason::DeAuthorized;
    case types::evse_manager::StopTransactionReason::EnergyLimitReached:
    case types::evse_manager::StopTransactionReason::GroundFault:
    case types::evse_manager::StopTransactionReason::LocalOutOfCredit:
    case types::evse_manager::StopTransactionReason::MasterPass:
    case types::evse_manager::StopTransactionReason::OvercurrentFault:
    case types::evse_manager::StopTransactionReason::PowerQuality:
    case types::evse_manager::StopTransactionReason::SOCLimitReached:
    case types::evse_manager::StopTransactionReason::StoppedByEV:
    case types::evse_manager::StopTransactionReason::TimeLimitReached:
    case types::evse_manager::StopTransactionReason::Timeout:
    case types::evse_manager::StopTransactionReason::ReqEnergyTransferRejected:
    case types::evse_manager::StopTransactionReason::Other:
        return ocpp::v16::Reason::Other;
    }
    throw std::out_of_range("Could not convert types::evse_manager::StopTransactionReason to ocpp::v16::Reason");
}

ocpp::v2::CertificateActionEnum to_ocpp_certificate_action_enum(const types::iso15118::CertificateActionEnum action) {
    switch (action) {
    case types::iso15118::CertificateActionEnum::Install:
        return ocpp::v2::CertificateActionEnum::Install;
    case types::iso15118::CertificateActionEnum::Update:
        return ocpp::v2::CertificateActionEnum::Update;
    }
    throw std::out_of_range(
        "Could not convert types::iso15118::CertificateActionEnum to ocpp::v2::CertificateActionEnum");
}

ocpp::v16::ReservationStatus to_ocpp_reservation_status(const types::reservation::ReservationResult result) {
    switch (result) {
    case types::reservation::ReservationResult::Accepted:
        return ocpp::v16::ReservationStatus::Accepted;
    case types::reservation::ReservationResult::Faulted:
        return ocpp::v16::ReservationStatus::Faulted;
    case types::reservation::ReservationResult::Occupied:
        return ocpp::v16::ReservationStatus::Occupied;
    case types::reservation::ReservationResult::Rejected:
        return ocpp::v16::ReservationStatus::Rejected;
    case types::reservation::ReservationResult::Unavailable:
        return ocpp::v16::ReservationStatus::Unavailable;
    }
    throw std::out_of_range("Could not convert types::reservation::ReservationResult to ocpp::v16::ReservationStatus");
}

ocpp::v16::LogStatusEnumType to_ocpp_log_status_enum_type(const types::system::UploadLogsStatus status) {
    switch (status) {
    case types::system::UploadLogsStatus::Accepted:
        return ocpp::v16::LogStatusEnumType::Accepted;
    case types::system::UploadLogsStatus::Rejected:
        return ocpp::v16::LogStatusEnumType::Rejected;
    case types::system::UploadLogsStatus::AcceptedCanceled:
        return ocpp::v16::LogStatusEnumType::AcceptedCanceled;
    }
    throw std::out_of_range("Could not convert types::system::UploadLogsStatus to ocpp::v16::LogStatusEnumType");
}

ocpp::v16::UpdateFirmwareStatusEnumType
to_ocpp_update_firmware_status_enum_type(const types::system::UpdateFirmwareResponse response) {
    switch (response) {
    case types::system::UpdateFirmwareResponse::Accepted:
        return ocpp::v16::UpdateFirmwareStatusEnumType::Accepted;
    case types::system::UpdateFirmwareResponse::Rejected:
        return ocpp::v16::UpdateFirmwareStatusEnumType::Rejected;
    case types::system::UpdateFirmwareResponse::AcceptedCanceled:
        return ocpp::v16::UpdateFirmwareStatusEnumType::AcceptedCanceled;
    case types::system::UpdateFirmwareResponse::InvalidCertificate:
        return ocpp::v16::UpdateFirmwareStatusEnumType::InvalidCertificate;
    case types::system::UpdateFirmwareResponse::RevokedCertificate:
        return ocpp::v16::UpdateFirmwareStatusEnumType::RevokedCertificate;
    }
    throw std::out_of_range(
        "Could not convert types::system::UpdateFirmwareResponse to ocpp::v16::UpdateFirmwareStatusEnumType");
}

ocpp::v16::HashAlgorithmEnumType to_ocpp_hash_algorithm_enum_type(const types::iso15118::HashAlgorithm hash_algorithm) {
    switch (hash_algorithm) {
    case types::iso15118::HashAlgorithm::SHA256:
        return ocpp::v16::HashAlgorithmEnumType::SHA256;
    case types::iso15118::HashAlgorithm::SHA384:
        return ocpp::v16::HashAlgorithmEnumType::SHA384;
    case types::iso15118::HashAlgorithm::SHA512:
        return ocpp::v16::HashAlgorithmEnumType::SHA512;
    }
    throw std::out_of_range("Could not convert types::iso15118::HashAlgorithm to ocpp::v16::HashAlgorithmEnumType");
}

ocpp::v16::BootReasonEnum to_ocpp_boot_reason_enum(const types::system::BootReason reason) {
    switch (reason) {
    case types::system::BootReason::ApplicationReset:
        return ocpp::v16::BootReasonEnum::ApplicationReset;
    case types::system::BootReason::FirmwareUpdate:
        return ocpp::v16::BootReasonEnum::FirmwareUpdate;
    case types::system::BootReason::LocalReset:
        return ocpp::v16::BootReasonEnum::LocalReset;
    case types::system::BootReason::PowerUp:
        return ocpp::v16::BootReasonEnum::PowerUp;
    case types::system::BootReason::RemoteReset:
        return ocpp::v16::BootReasonEnum::RemoteReset;
    case types::system::BootReason::ScheduledReset:
        return ocpp::v16::BootReasonEnum::ScheduledReset;
    case types::system::BootReason::Triggered:
        return ocpp::v16::BootReasonEnum::Triggered;
    case types::system::BootReason::Unknown:
        return ocpp::v16::BootReasonEnum::Unknown;
    case types::system::BootReason::Watchdog:
        return ocpp::v16::BootReasonEnum::Watchdog;
    }
    throw std::runtime_error("Could not convert BootReasonEnum");
}

ocpp::Powermeter to_ocpp_power_meter(const types::powermeter::Powermeter& powermeter) {
    ocpp::Powermeter ocpp_powermeter;
    ocpp_powermeter.timestamp = ocpp_conversions::to_ocpp_datetime_or_now(powermeter.timestamp);
    ocpp_powermeter.energy_Wh_import = {powermeter.energy_Wh_import.total, powermeter.energy_Wh_import.L1,
                                        powermeter.energy_Wh_import.L2, powermeter.energy_Wh_import.L3};

    ocpp_powermeter.meter_id = powermeter.meter_id;
    ocpp_powermeter.phase_seq_error = powermeter.phase_seq_error;

    if (powermeter.energy_Wh_export.has_value()) {
        const auto energy_wh_export = powermeter.energy_Wh_export.value();
        ocpp_powermeter.energy_Wh_export =
            ocpp::Energy{energy_wh_export.total, energy_wh_export.L1, energy_wh_export.L2, energy_wh_export.L3};
    }

    if (powermeter.power_W.has_value()) {
        const auto power_w = powermeter.power_W.value();
        ocpp_powermeter.power_W = ocpp::Power{power_w.total, power_w.L1, power_w.L2, power_w.L3};
    }

    if (powermeter.voltage_V.has_value()) {
        const auto voltage_v = powermeter.voltage_V.value();
        ocpp_powermeter.voltage_V = ocpp::Voltage{voltage_v.DC, voltage_v.L1, voltage_v.L2, voltage_v.L3};
    }

    if (powermeter.VAR.has_value()) {
        const auto var = powermeter.VAR.value();
        ocpp_powermeter.VAR = ocpp::ReactivePower{var.total, var.L1, var.L2, var.L3};
    }

    if (powermeter.current_A.has_value()) {
        const auto current_a = powermeter.current_A.value();
        ocpp_powermeter.current_A = ocpp::Current{current_a.DC, current_a.L1, current_a.L2, current_a.L3, current_a.N};
    }

    if (powermeter.frequency_Hz.has_value()) {
        const auto frequency_hz = powermeter.frequency_Hz.value();
        ocpp_powermeter.frequency_Hz = ocpp::Frequency{frequency_hz.L1, frequency_hz.L2, frequency_hz.L3};
    }

    return ocpp_powermeter;
}

std::vector<ocpp::Temperature> to_ocpp_temperatures(const std::vector<types::temperature::Temperature>& temperatures) {
    std::vector<ocpp::Temperature> ocpp_temperatures;
    for (const auto temperature : temperatures) {
        ocpp::Temperature ocpp_temperature;
        ocpp_temperature.value = temperature.temperature;
        if (temperature.location.has_value()) {
            ocpp_temperature.location = temperature.location.value();
        }
        ocpp_temperatures.push_back(ocpp_temperature);
    }
    return ocpp_temperatures;
}

ocpp::v2::HashAlgorithmEnum to_ocpp_hash_algorithm_enum(const types::iso15118::HashAlgorithm hash_algorithm) {
    switch (hash_algorithm) {
    case types::iso15118::HashAlgorithm::SHA256:
        return ocpp::v2::HashAlgorithmEnum::SHA256;
    case types::iso15118::HashAlgorithm::SHA384:
        return ocpp::v2::HashAlgorithmEnum::SHA384;
    case types::iso15118::HashAlgorithm::SHA512:
        return ocpp::v2::HashAlgorithmEnum::SHA512;
    }
    throw std::out_of_range("Could not convert types::iso15118::HashAlgorithm to ocpp::v16::HashAlgorithmEnumType");
}

types::evse_manager::StopTransactionReason to_everest_stop_transaction_reason(const ocpp::v16::Reason reason) {
    switch (reason) {
    case ocpp::v16::Reason::EmergencyStop:
        return types::evse_manager::StopTransactionReason::EmergencyStop;
    case ocpp::v16::Reason::EVDisconnected:
        return types::evse_manager::StopTransactionReason::EVDisconnected;
    case ocpp::v16::Reason::HardReset:
        return types::evse_manager::StopTransactionReason::HardReset;
    case ocpp::v16::Reason::Local:
        return types::evse_manager::StopTransactionReason::Local;
    case ocpp::v16::Reason::PowerLoss:
        return types::evse_manager::StopTransactionReason::PowerLoss;
    case ocpp::v16::Reason::Reboot:
        return types::evse_manager::StopTransactionReason::Reboot;
    case ocpp::v16::Reason::Remote:
        return types::evse_manager::StopTransactionReason::Remote;
    case ocpp::v16::Reason::SoftReset:
        return types::evse_manager::StopTransactionReason::SoftReset;
    case ocpp::v16::Reason::UnlockCommand:
        return types::evse_manager::StopTransactionReason::UnlockCommand;
    case ocpp::v16::Reason::DeAuthorized:
        return types::evse_manager::StopTransactionReason::DeAuthorized;
    case ocpp::v16::Reason::Other:
        return types::evse_manager::StopTransactionReason::Other;
    }
    throw std::out_of_range("Could not convert ocpp::v16::Reason to types::evse_manager::StopTransactionReason");
}

types::system::ResetType to_everest_reset_type(const ocpp::v16::ResetType type) {
    switch (type) {
    case ocpp::v16::ResetType::Hard:
        return types::system::ResetType::Hard;
    case ocpp::v16::ResetType::Soft:
        return types::system::ResetType::Soft;
    }
    throw std::out_of_range("Could not convert ocpp::v16::ResetType to types::system::ResetType");
}

types::iso15118::Status to_everest_iso15118_status(const ocpp::v2::Iso15118EVCertificateStatusEnum status) {
    switch (status) {
    case ocpp::v2::Iso15118EVCertificateStatusEnum::Accepted:
        return types::iso15118::Status::Accepted;
    case ocpp::v2::Iso15118EVCertificateStatusEnum::Failed:
        return types::iso15118::Status::Failed;
    }
    throw std::out_of_range("Could not convert ocpp::v2::Iso15118EVCertificateStatusEnum to types::iso15118::Status");
}

types::iso15118::CertificateActionEnum
to_everest_certificate_action_enum(const ocpp::v2::CertificateActionEnum action) {
    switch (action) {
    case ocpp::v2::CertificateActionEnum::Install:
        return types::iso15118::CertificateActionEnum::Install;
    case ocpp::v2::CertificateActionEnum::Update:
        return types::iso15118::CertificateActionEnum::Update;
    }
    throw std::out_of_range(
        "Could not convert ocpp::v2::CertificateActionEnum to types::iso15118::CertificateActionEnum");
}

types::authorization::CertificateStatus
to_everest_certificate_status(const ocpp::v2::AuthorizeCertificateStatusEnum status) {
    switch (status) {
    case ocpp::v2::AuthorizeCertificateStatusEnum::Accepted:
        return types::authorization::CertificateStatus::Accepted;
    case ocpp::v2::AuthorizeCertificateStatusEnum::SignatureError:
        return types::authorization::CertificateStatus::SignatureError;
    case ocpp::v2::AuthorizeCertificateStatusEnum::CertificateExpired:
        return types::authorization::CertificateStatus::CertificateExpired;
    case ocpp::v2::AuthorizeCertificateStatusEnum::CertificateRevoked:
        return types::authorization::CertificateStatus::CertificateRevoked;
    case ocpp::v2::AuthorizeCertificateStatusEnum::NoCertificateAvailable:
        return types::authorization::CertificateStatus::NoCertificateAvailable;
    case ocpp::v2::AuthorizeCertificateStatusEnum::CertChainError:
        return types::authorization::CertificateStatus::CertChainError;
    case ocpp::v2::AuthorizeCertificateStatusEnum::ContractCancelled:
        return types::authorization::CertificateStatus::ContractCancelled;
    }
    throw std::out_of_range(
        "Could not convert ocpp::v2::AuthorizeCertificateStatusEnum to types::authorization::CertificateStatus");
}

types::authorization::AuthorizationStatus to_everest_authorization_status(const ocpp::v16::AuthorizationStatus status) {
    switch (status) {
    case ocpp::v16::AuthorizationStatus::Accepted:
        return types::authorization::AuthorizationStatus::Accepted;
    case ocpp::v16::AuthorizationStatus::Blocked:
        return types::authorization::AuthorizationStatus::Blocked;
    case ocpp::v16::AuthorizationStatus::Expired:
        return types::authorization::AuthorizationStatus::Expired;
    case ocpp::v16::AuthorizationStatus::Invalid:
        return types::authorization::AuthorizationStatus::Invalid;
    case ocpp::v16::AuthorizationStatus::ConcurrentTx:
        return types::authorization::AuthorizationStatus::ConcurrentTx;
    }
    throw std::out_of_range(
        "Could not convert ocpp::v16::AuthorizationStatus to types::authorization::AuthorizationStatus");
}

types::authorization::AuthorizationStatus
to_everest_authorization_status(const ocpp::v2::AuthorizationStatusEnum status) {
    switch (status) {
    case ocpp::v2::AuthorizationStatusEnum::Accepted:
        return types::authorization::AuthorizationStatus::Accepted;
    case ocpp::v2::AuthorizationStatusEnum::Blocked:
        return types::authorization::AuthorizationStatus::Blocked;
    case ocpp::v2::AuthorizationStatusEnum::ConcurrentTx:
        return types::authorization::AuthorizationStatus::ConcurrentTx;
    case ocpp::v2::AuthorizationStatusEnum::Expired:
        return types::authorization::AuthorizationStatus::Expired;
    case ocpp::v2::AuthorizationStatusEnum::Invalid:
        return types::authorization::AuthorizationStatus::Invalid;
    case ocpp::v2::AuthorizationStatusEnum::NoCredit:
        return types::authorization::AuthorizationStatus::NoCredit;
    case ocpp::v2::AuthorizationStatusEnum::NotAllowedTypeEVSE:
        return types::authorization::AuthorizationStatus::NotAllowedTypeEVSE;
    case ocpp::v2::AuthorizationStatusEnum::NotAtThisLocation:
        return types::authorization::AuthorizationStatus::NotAtThisLocation;
    case ocpp::v2::AuthorizationStatusEnum::NotAtThisTime:
        return types::authorization::AuthorizationStatus::NotAtThisTime;
    case ocpp::v2::AuthorizationStatusEnum::Unknown:
        return types::authorization::AuthorizationStatus::Unknown;
    }
    throw std::out_of_range(
        "Could not convert ocpp::v2::AuthorizationStatusEnum to types::authorization::AuthorizationStatus");
}

types::ocpp::ChargingSchedulePeriod
to_charging_schedule_period(const ocpp::v16::EnhancedChargingSchedulePeriod& period) {
    types::ocpp::ChargingSchedulePeriod csp;
    csp.start_period = period.startPeriod;
    csp.limit = period.limit;
    csp.number_phases = period.numberPhases;
    csp.stack_level = period.stackLevel;
    return csp;
}

types::ocpp::ChargingSchedule to_charging_schedule(const ocpp::v16::EnhancedChargingSchedule& schedule) {
    types::ocpp::ChargingSchedule csch = {
        0,
        ocpp::v16::conversions::charging_rate_unit_to_string(schedule.chargingRateUnit),
        {},
        schedule.duration,
        std::nullopt,
        schedule.minChargingRate};
    for (const auto& i : schedule.chargingSchedulePeriod) {
        csch.charging_schedule_period.emplace_back(to_charging_schedule_period(i));
    }
    if (schedule.startSchedule.has_value()) {
        csch.start_schedule = schedule.startSchedule.value().to_rfc3339();
    }
    return csch;
}

types::ocpp::BootNotificationResponse
to_everest_boot_notification_response(const ocpp::v16::BootNotificationResponse& boot_notification_response) {
    types::ocpp::BootNotificationResponse everest_boot_notification_response;
    everest_boot_notification_response.status = to_everest_registration_status(boot_notification_response.status);
    everest_boot_notification_response.current_time = boot_notification_response.currentTime.to_rfc3339();
    everest_boot_notification_response.interval = boot_notification_response.interval;
    return everest_boot_notification_response;
}

types::ocpp::RegistrationStatus
to_everest_registration_status(const ocpp::v16::RegistrationStatus& registration_status) {
    switch (registration_status) {
    case ocpp::v16::RegistrationStatus::Accepted:
        return types::ocpp::RegistrationStatus::Accepted;
    case ocpp::v16::RegistrationStatus::Pending:
        return types::ocpp::RegistrationStatus::Pending;
    case ocpp::v16::RegistrationStatus::Rejected:
        return types::ocpp::RegistrationStatus::Rejected;
    }
    throw std::out_of_range("Could not convert ocpp::v2::RegistrationStatus to types::ocpp::RegistrationStatus");
}

ocpp::v16::DataTransferStatus
to_ocpp_data_transfer_status(const types::display_message::DisplayMessageStatusEnum display_message_status_enum) {
    switch (display_message_status_enum) {
    case types::display_message::DisplayMessageStatusEnum::Accepted:
        return ocpp::v16::DataTransferStatus::Accepted;
    case types::display_message::DisplayMessageStatusEnum::NotSupportedMessageFormat:
        return ocpp::v16::DataTransferStatus::Rejected;
    case types::display_message::DisplayMessageStatusEnum::Rejected:
        return ocpp::v16::DataTransferStatus::Rejected;
    case types::display_message::DisplayMessageStatusEnum::NotSupportedPriority:
        return ocpp::v16::DataTransferStatus::Rejected;
    case types::display_message::DisplayMessageStatusEnum::NotSupportedState:
        return ocpp::v16::DataTransferStatus::Rejected;
    case types::display_message::DisplayMessageStatusEnum::UnknownTransaction:
        return ocpp::v16::DataTransferStatus::Rejected;
    }
    throw std::out_of_range(
        "Could not convert types::display_message::DisplayMessageStatusEnum to ocpp::v16::DataTransferStatus");
}

ocpp::v16::DataTransferResponse
to_ocpp_data_transfer_response(const types::display_message::SetDisplayMessageResponse& set_display_message_response) {
    ocpp::v16::DataTransferResponse response;
    response.status = to_ocpp_data_transfer_status(set_display_message_response.status);

    response.data = set_display_message_response.status_info;
    return response;
}
} // namespace conversions
} // namespace module
