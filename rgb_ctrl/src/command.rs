pub mod set_color;

pub enum CommandType {
    SetColor = 0x01,
}

pub trait Command {
    // Return the corresponding command ID for this command
    fn command_id(&self) -> u8;
    // Serialize all relevant parameters into an array of bytes
    fn to_bytes(&self) -> Vec<u8>;
}

// Convert a Command into a HID report
pub fn command_to_report<C>(command: C) -> anyhow::Result<[u8; 33]>
where
    C: Command,
{
    let command_bytes = command.to_bytes();
    let command_id = command.command_id();

    tracing::debug!(
        "Converting command ID {:02x} with bytes {:02x?} to report",
        command_id,
        &command_bytes
    );

    let mut report = [0u8; 33];
    report[0] = 0x00; // report ID
    report[1] = command_id; // command ID

    // Fill in command-specific bytes. Could be variable number of bytes.
    for (i, byte) in command_bytes.iter().enumerate() {
        if i < 32 {
            report[2 + i] = *byte;
        } else {
            return Err(anyhow::anyhow!("Command bytes exceed report size"));
        }
    }

    Ok(report)
}

