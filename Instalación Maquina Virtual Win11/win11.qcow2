This document provides a step-by-step guide for installing and configuring Windows 11 in a virtualized environment using virt-manager and KVM (Kernel-based Virtual Machine) on a Linux host such as Kali, Ubuntu, or Fedora.

The goal is to create a fully functional Windows 11 virtual machine that:

Operates as a complete Windows installation with access to Microsoft Store, Windows Subsystem for Linux (WSL), and all standard Windows features.

Uses VirtIO drivers for optimal disk and network performance.

Supports USB passthrough for devices such as game controllers or peripherals.

Enables users to run GPU-dependent services like GeForce NOW, development tools, and Windows-only applications without rebooting into a dedicated Windows partition.

This guide is designed for engineers, developers, and system operators who need an isolated, high-performance Windows environment inside a Linux-based workstation — without sacrificing hardware recognition, network performance, or usability.

## 🧭 WINDOWS 11 VIRTUAL MACHINE SETUP (Virt-Manager + VirtIO Drivers)

### 📦 PREREQUISITES

1. Install the necessary packages:

   ```bash
   sudo apt update
   sudo apt install qemu-kvm libvirt-daemon-system virt-manager
   sudo systemctl enable --now libvirtd
   ```

2. Download these two ISO files:

   * **Windows 11 ISO:**
     [https://www.microsoft.com/software-download/windows11](https://www.microsoft.com/software-download/windows11)
   * **VirtIO Drivers ISO (latest):**
     [https://fedorapeople.org/groups/virt/virtio-win/direct-downloads/latest-virtio/](https://fedorapeople.org/groups/virt/virtio-win/direct-downloads/latest-virtio/)

3. Move both ISOs into libvirt’s default storage directory (so permissions never break):

   ```bash
   sudo mv ~/Downloads/Win11_25H2_English_x64.iso /var/lib/libvirt/images/
   sudo mv ~/Downloads/virtio-win-0.1.285.iso /var/lib/libvirt/images/
   ```

---

### 🖥️ STEP 1 — Create the Windows 11 VM

1. Launch Virtual Machine Manager:

   ```bash
   virt-manager &
   ```
2. Click **Create a new virtual machine** →
   Choose **Local install media (ISO image)** →
   Browse to:

   ```
   /var/lib/libvirt/images/Win11_25H2_English_x64.iso
   ```
3. Set:

   * **OS type:** Microsoft Windows 11
   * **Memory:** 16384 MiB (16 GB) or more
   * **CPUs:** 10–12
4. For **storage**, create a **new disk**:

   * Size: 128–150 GiB
   * Format: qcow2
   * Path: `/var/lib/libvirt/images/Windows11.qcow2`
5. Check **Customize configuration before install** and click **Finish.**

---

### ⚙️ STEP 2 — Configure the VM before installation

1. **Overview**

   * Chipset: `Q35`
   * Firmware: `UEFI`

2. **SATA Disk 1 (Windows11.qcow2)**

   * Change **Disk Bus** to `VirtIO`.

3. **NIC (Network Card)**

   * Change **Device Model** to `virtio`.

4. **SATA CDROM 1**

   * Confirm it points to your Windows ISO.

5. **Add VirtIO Driver CD**

   * Click **Add Hardware → Storage**
   * Choose **Select or create custom storage**
   * Browse to `/var/lib/libvirt/images/virtio-win-0.1.285.iso`
   * Set:

     * **Device type:** CDROM
     * **Bus type:** **IDE** (important — Windows can’t always read SATA driver discs)
   * Click **Finish**

You should now have:

```
SATA Disk 1        → Windows drive (VirtIO)
SATA CDROM 1       → Windows 11 installer
IDE CDROM 2        → VirtIO drivers
```

---

### 💿 STEP 3 — Install Windows

1. Click **Begin Installation** to start the VM.
2. Proceed through setup until you reach:

   ```
   "Where do you want to install Windows?"
   ```

   (It will show no drives.)
3. Click **Load Driver → Browse → CD Drive (E:)**
   Navigate to:

   ```
   viostor → w11 → amd64 → OK
   ```
4. Select the driver and click **Next** — your disk (e.g. Drive 0 Unallocated Space 150 GB) will now appear.
5. Select it and click **Next** to begin installation.

---

### 🌐 STEP 4 — Install VirtIO Network Drivers (after Windows boots)

Once Windows finishes installing and boots into the desktop:

1. Open **File Explorer** → open the **VirtIO CD (E:)**.
2. Run:

   ```
   virtio-win-guest-tools.exe
   ```

   This installs all VirtIO drivers (network, balloon, display, etc.) in one go.
3. If you prefer manually:

   * Go to **Device Manager** → right-click unknown network device →
     **Update Driver → Browse → E:\NetKVM\w11\amd64**

---

### 🧹 STEP 5 — Cleanup

1. Shut down the VM after everything works.
2. In virt-manager:

   * Remove both CDROMs (Windows ISO and VirtIO ISO).
3. Optionally delete the ISO files if you don’t plan to reuse them:

   ```bash
   sudo rm /var/lib/libvirt/images/Win11_25H2_English_x64.iso
   sudo rm /var/lib/libvirt/images/virtio-win-0.1.285.iso
   ```

---

### ⚡ OPTIONAL — USB Controller / Gamepad Passthrough

If you want to use a wired game controller or USB device:

1. Start the VM.
2. In virt-manager → top menu → **View → Details → Add Hardware → USB Host Device.**
3. Pick your controller → **Finish.**
4. Windows will recognize it as if it were plugged directly in.

---

### ✅ RESULT

You now have:

* A Windows 11 VM with VirtIO disk and network (high performance)
* Full Internet connectivity
* USB device passthrough support
* Reusable configuration steps for any machine